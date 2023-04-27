/***************************************************************************//**
*  \file       test_ioctl_app.c
*
*  \details    Userspace application to test the Device driver
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
 
#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)
 
int main()
{
        int fd;
        int32_t value, number;
         
        printf("\nOpening Driver : \"/dev/test_device\"\r\n");
        fd = open("/dev/test_device", O_RDWR,0777);
        if(fd < 0) {
                printf("Cannot open device file...\r\n");
                return 0;
        }
 
        printf("Enter the Value to send\r\n");
        scanf("%d",&number);
        printf("Writing Value to Driver\r\n");
        ioctl(fd, WR_VALUE, (int32_t*) &number); 
 
        printf("Reading Value from Driver\r\n");
        ioctl(fd, RD_VALUE, (int32_t*) &value);
        printf("Recived Value is %d\r\n", value);
 
        printf("Closing Driver\n");
        close(fd);
}