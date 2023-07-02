/*
 * lcd_i2c.c
 *
 *  Created on: 28-Jun-2023
 *      Author: nithish
 */

#include "lcd_i2c.h"
#include "i2c.h"

// LCD commands
#define LCD_CMD_CLEAR_DISPLAY      0x01
#define LCD_CMD_RETURN_HOME        0x02
#define LCD_CMD_ENTRY_MODE_SET     0x04
#define LCD_CMD_DISPLAY_CONTROL    0x08
#define LCD_CMD_CURSOR_SHIFT       0x10
#define LCD_CMD_FUNCTION_SET       0x20
#define LCD_CMD_SET_CGRAM_ADDR     0x40
#define LCD_CMD_SET_DDRAM_ADDR     0x80

// LCD flags for display entry mode
#define LCD_FLAG_ENTRY_RIGHT       0x00
#define LCD_FLAG_ENTRY_LEFT        0x02
#define LCD_FLAG_ENTRY_SHIFT_INC   0x01
#define LCD_FLAG_ENTRY_SHIFT_DEC   0x00

// LCD flags for display on/off control
#define LCD_FLAG_DISPLAY_ON        0x04
#define LCD_FLAG_DISPLAY_OFF       0x00
#define LCD_FLAG_CURSOR_ON         0x02
#define LCD_FLAG_CURSOR_OFF        0x00
#define LCD_FLAG_BLINK_ON          0x01
#define LCD_FLAG_BLINK_OFF         0x00

// LCD flags for cursor or display shift
#define LCD_FLAG_DISPLAY_SHIFT     0x08
#define LCD_FLAG_CURSOR_MOVE       0x00
#define LCD_FLAG_SHIFT_RIGHT       0x04
#define LCD_FLAG_SHIFT_LEFT        0x00

// LCD flags for function set
#define LCD_FLAG_8BIT_MODE         0x10
#define LCD_FLAG_4BIT_MODE         0x00
#define LCD_FLAG_2LINE             0x08
#define LCD_FLAG_1LINE             0x00
#define LCD_FLAG_5x10_DOTS         0x04
#define LCD_FLAG_5x8_DOTS          0x00

// LCD backlight control
#define LCD_BACKLIGHT_ON           0x08
#define LCD_BACKLIGHT_OFF          0x00

// LCD display and cursor position
static uint8_t lcd_display_control = LCD_FLAG_DISPLAY_ON | LCD_FLAG_CURSOR_OFF | LCD_FLAG_BLINK_OFF;
static uint8_t lcd_entry_mode = LCD_FLAG_ENTRY_LEFT | LCD_FLAG_ENTRY_SHIFT_DEC;
static uint8_t lcd_display_function = LCD_FLAG_4BIT_MODE | LCD_FLAG_2LINE | LCD_FLAG_5x8_DOTS;

// LCD I2C address
#define LCD_I2C_ADDRESS           0x3F

// I2C handle
extern I2C_HandleTypeDef hi2c1;

// Private functions
static void LCD_SendCmd(uint8_t cmd);
static void LCD_SendData(uint8_t data);
static void LCD_SendHalfByte(uint8_t data);
static void LCD_SendByte(uint8_t data, uint8_t mode);
static void LCD_SendString(const char* str);

void LCD_Init(void)
{
  HAL_Delay(50);  // Wait for LCD power-up

  // Initialize LCD in 4-bit mode
  LCD_SendHalfByte(0x03);
  HAL_Delay(5);
  LCD_SendHalfByte(0x03);
  HAL_Delay(1);
  LCD_SendHalfByte(0x03);
  HAL_Delay(1);
  LCD_SendHalfByte(0x02);

  // Function Set
  LCD_SendCmd(LCD_CMD_FUNCTION_SET | lcd_display_function);

  // Display On/Off Control
  LCD_SendCmd(LCD_CMD_DISPLAY_CONTROL | lcd_display_control);

  // Clear Display
  LCD_SendCmd(LCD_CMD_CLEAR_DISPLAY);

  // Entry Mode Set
  LCD_SendCmd(LCD_CMD_ENTRY_MODE_SET | lcd_entry_mode);

  // Set backlight on
  LCD_BacklightOn();
}

void LCD_Clear(void)
{
  LCD_SendCmd(LCD_CMD_CLEAR_DISPLAY);
  HAL_Delay(2);
}

void LCD_SetCursor(uint8_t col, uint8_t row)
{
  uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};

  if (row >= 2) {
    row = 1;
  }

  LCD_SendCmd(LCD_CMD_SET_DDRAM_ADDR | (col + row_offsets[row]));
}

void LCD_Print(const char* str)
{
  LCD_SendString(str);
}

void LCD_BacklightOn(void)
{
  uint8_t data = 0x00;
  data |= LCD_BACKLIGHT_ON;
  LCD_SendByte(data, 0);
}

void LCD_BacklightOff(void)
{
  uint8_t data = 0x00;
  data |= LCD_BACKLIGHT_OFF;
  LCD_SendByte(data, 0);
}

static void LCD_SendCmd(uint8_t cmd)
{
  LCD_SendByte(cmd, 0);
}

static void LCD_SendData(uint8_t data)
{
  LCD_SendByte(data, 1);
}

static void LCD_SendHalfByte(uint8_t data)
{
  uint8_t high_nibble = data & 0xF0;
  uint8_t low_nibble = (data << 4) & 0xF0;

  LCD_SendByte(high_nibble, 1);
  LCD_SendByte(low_nibble, 1);
}

static void LCD_SendByte(uint8_t data, uint8_t mode)
{
  uint8_t data_high = data & 0xF0;
  //uint8_t data_low = (data << 4) & 0xF0;

  uint8_t lcd_data = 0x00;
  lcd_data |= data_high;

  if (mode == 1) {
    lcd_data |= 0x01;  // RS = 1 for data
  }

  lcd_data |= LCD_BACKLIGHT_ON;

  // Send the data via I2C
  HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDRESS, &lcd_data, 1, 100);

  lcd_data &= ~0x04;  // E = 0
  HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDRESS, &lcd_data, 1, 100);

  lcd_data |= 0x04;   // E = 1
  HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDRESS, &lcd_data, 1, 100);

  if (mode == 0) {
    HAL_Delay(1);
  }

  lcd_data &= ~0x04;  // E = 0
  HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDRESS, &lcd_data, 1, 100);

  HAL_Delay(1);

  lcd_data |= 0x08;   // BL = 1
  HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDRESS, &lcd_data, 1, 100);
}

static void LCD_SendString(const char* str)
{
  while (*str) {
    LCD_SendData((uint8_t)(*str));
    str++;
  }
}
