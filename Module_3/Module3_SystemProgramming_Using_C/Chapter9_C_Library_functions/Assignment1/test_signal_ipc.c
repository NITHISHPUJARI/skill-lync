#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Handler function declaration
void sighupHandler();
void sigintHandler();
void sigquitHandler();

// Main code
int main() {
  int pid;

  /* get child process */
  if ((pid = fork()) < 0) {
    perror("fork");
    exit(1);
  }

  if (pid == 0) { /* child */
    signal(SIGHUP, sighupHandler);
    signal(SIGINT, sigintHandler);
    signal(SIGQUIT, sigquitHandler);
    for (;;)
      ; /* loop for ever */
  }

  else /* parent */
  {    /* pid hold id of child */
    printf("\nPARENT Process: sending SIGHUP\r\n\n");
    kill(pid, SIGHUP);

    sleep(3); /* pause for 3 secs */
    printf("\nPARENT Process: sending SIGINT\r\n\n");
    kill(pid, SIGINT);

    sleep(3); /* pause for 3 secs */
    printf("\nPARENT Process: sending SIGQUIT\r\n\n");
    kill(pid, SIGQUIT);
    sleep(3);
  }
  printf("\nPARENT Process: Done!!\n\n");
  return 0;
}

// sighupHandler() function definition
void sighupHandler() {
  signal(SIGHUP, sighupHandler); /* reset signal */
  printf("[%s] CHILD Process: I have received a SIGHUP\r\n", __FUNCTION__);
}

// sigintHandler() function definition
void sigintHandler() {
  signal(SIGINT, sigintHandler); /* reset signal */
  printf("[%s] CHILD Process: I have received a SIGINT\r\n", __FUNCTION__);
}

// sigquitHandler() function definition
void sigquitHandler() {
  printf("[%s] CHILD Process: My Parent has Killed me!!!\r\n", __FUNCTION__);
  exit(0);
}
