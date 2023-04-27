#include <stdio.h>
#include <inttypes.h>

typedef union
{
    uint32_t u32RawData;        
    uint8_t  u8DataBuff[4];
} RawData;

uint32_t ChangeEndianness(uint32_t u32Value)
{
    RawData uChangeData,uOrginalData;
    uOrginalData.u32RawData = u32Value;
    //change the value
    uChangeData.u8DataBuff[0]  = uOrginalData.u8DataBuff[3];
    uChangeData.u8DataBuff[1]  = uOrginalData.u8DataBuff[2];
    uChangeData.u8DataBuff[2]  = uOrginalData.u8DataBuff[1];
    uChangeData.u8DataBuff[3]  = uOrginalData.u8DataBuff[0];
    return (uChangeData.u32RawData);
}
int main()
{
    uint32_t u32CheckData  = 0x11223344;
    uint32_t u32ResultData =0;
    u32ResultData = ChangeEndianness(u32CheckData);
    printf("Orignal Byte Order   = 0x%x\r\n",u32CheckData);
    printf("Converted Byte Order = 0x%x\r\n",u32ResultData);
    return 0;
}