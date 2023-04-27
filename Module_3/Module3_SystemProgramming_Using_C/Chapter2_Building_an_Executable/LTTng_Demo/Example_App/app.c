#include <stdlib.h>
#include <stdio.h>

#include "myTp.h"
#include "app.h"

static int array_of_ints[] = {
    100,
    -35,
    1,
    23,
    14,
    -6,
    28,
    1001,
    -3000,
};

int main(int argc, char *argv[])
{
    FILE *stream;
    struct app_struct app_struct;
    // Trace Number of Arguments & Argument at 0
    lttng_ust_tracepoint(my_provider, simple_event, argc, argv[0]);

    for (int i = 0; i < argc; i++)
    {
        // Trace all the arguments
        lttng_ust_tracepoint(my_provider, simple_event,
                             i, argv[i]);
    }

    // Open file to write some data
    stream = fopen("testFile.txt", "w+");

    if (!stream)
    {
        fprintf(stderr,
                "Error: Cannot open testFile.txt for writing\n");
        return EXIT_FAILURE;
    }

    if (fprintf(stream, "0123456789") != 10)
    {
        fclose(stream);
        fprintf(stderr, "Error: Cannot write to testFile.txt\n");
        return EXIT_FAILURE;
    }

    // At any point in App you can use the big_evnt tracepoint defination
    lttng_ust_tracepoint(my_provider, big_event, 10,
                         "hello tracepoint", stream, -3.14,
                         array_of_ints);
    fclose(stream);

    // Example usage for different tracepoint definations
    app_struct.b = argc;
    app_struct.c = "App at Stage : 1";
    lttng_ust_tracepoint(my_provider, event_instance1, 23,
                         &app_struct);
    app_struct.b = argc * 5;
    app_struct.c = "App at Stage : 2";
    lttng_ust_tracepoint(my_provider, event_instance2, 17,
                         &app_struct);
    app_struct.b = 23;
    app_struct.c = "Closing App";
    lttng_ust_tracepoint(my_provider, event_instance3, -52,
                         &app_struct);
    return EXIT_SUCCESS;
}