#include <time.h>
#include <stdio.h>

#define PST (-8)
#define CET (1)

int main(void)
{
    // Readable Current Local Time using ctime:
    time_t mytime;
    mytime = time(NULL);
    printf("An example of ctime() use:\r\n");
    printf("Local Time : %s\r\n", ctime(&mytime));
    

    // Manipulating the time structure with mktime():
    struct tm str_time;
    time_t time_of_day;

    str_time.tm_year = 2212 - 1900;
    str_time.tm_mon = 6;
    str_time.tm_mday = 5;
    str_time.tm_hour = 10;
    str_time.tm_min = 3;
    str_time.tm_sec = 5;
    str_time.tm_isdst = 0;

    time_of_day = mktime(&str_time);
    printf("An example of mktime() use:\r\n");
    printf("manipulate the time into the future : %s\r\n", ctime(&time_of_day));

    // Using the function difftime:
    time_t start, end;
    volatile long unsigned counter;

    start = time(NULL);

    for (counter = 0; counter < 500000000; counter++)
        ; /* Do nothing, just loop */

    end = time(NULL);
    printf("An example of difftime() use:\r\n");
    printf("The loop used %f seconds.\r\n", difftime(end, start));

    // work with different timeszones by using gmtime() to convert calendar time to UTC:
    time_t raw_time;
    struct tm *ptr_ts;

    time(&raw_time);
    ptr_ts = gmtime(&raw_time);

    printf("\r\nAn example of gmtime() use:\r\n");
    printf("Time Los Angeles: %2d:%02d\r\n",
           ptr_ts->tm_hour + PST, ptr_ts->tm_min);
    printf("Time Amsterdam: %2d:%02d\r\n",
           ptr_ts->tm_hour + CET, ptr_ts->tm_min);

    return 0;
}