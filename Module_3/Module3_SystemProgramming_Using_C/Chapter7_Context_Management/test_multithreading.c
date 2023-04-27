#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

// Mutex for lock on the variable or a shared resourcec:
pthread_mutex_t lock;
// Global variable :
// Every process should have the exclusive access 
volatile int ProcCount;

void test_proc()
{
    // Current Thread ID:
    printf("I am from Thread: 0x%0X\r\n",(int)pthread_self());
    sleep(2);
    // Lock the Mutex:
    pthread_mutex_lock(&lock);
    int i = 0;

    // Shared variable between all the processes:
    // This Variable is incremented by each process.
    ProcCount++;

    // Some tasks:
    while (i < 5)
    {
        printf("%d", ProcCount);
        sleep(1);
        i++;
    }
    printf("...Done : 0x%0X\r\n", (int)pthread_self());
    // Unlock the mutex:
    pthread_mutex_unlock(&lock);
}

int main(void)
{
    int err;
    pthread_t t1, t2, t3;
    int ProcessNum = 0;

    // Mutex init:
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    // Init the variable to 0
    ProcCount = 0;
    
    // Create 3 threads which execute the test_proc()
    pthread_create(&t1, NULL, (void*)test_proc, NULL);
    pthread_create(&t2, NULL, (void*)test_proc, NULL);
    pthread_create(&t3, NULL, (void*)test_proc, NULL);

    // Wait for a thread to terminate, detaches the thread, 
    // Finnaly returns the threads exit status
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}