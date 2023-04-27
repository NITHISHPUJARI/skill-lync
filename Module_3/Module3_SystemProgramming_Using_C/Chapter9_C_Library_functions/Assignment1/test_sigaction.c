#include <signal.h>
#include <stdio.h>
#include <sys/time.h>

// An integral type that can be modified atomically,
// without the possibility of a signal arriving in the middle of the operation.
static volatile sig_atomic_t g_Count;

// SIGALRM Signal Handler:
void TimerHandler(int sig) {
  g_Count += 1;
  printf("[%s] Do timely Task Here\r\n[%s]g_Count -: %d called times\r\n",
         __FUNCTION__, __FUNCTION__, g_Count);
}

int main() {
  struct sigaction act, oact;
  g_Count = 0;

  // Initialize and empty a signal set
  // https://man7.org/linux/man-pages/man3/sigemptyset.3p.html
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  act.sa_handler = TimerHandler; // New Handler for Sigaction

  // SIGALRM is an asynchronous signal.
  // The SIGALRM signal is raised when a time interval specified
  // in a call to the alarm or alarmd function expires.
  sigaction(SIGALRM, &act, &oact);

  // Set Value for Interval Timer
  struct itimerval tv;
  tv.it_value.tv_sec = 2;     // time of first timer
  tv.it_value.tv_usec = 0;    // time of first timer
  tv.it_interval.tv_sec = 2;  // time of all timers but the first one
  tv.it_interval.tv_usec = 0; // time of all timers but the first one
  setitimer(ITIMER_REAL, &tv, NULL);

  while (1) {
  }
  return 0;
}