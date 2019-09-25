#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int count = 0;

int main(){
  static struct sigaction act;

  void catchint(int);

  act.sa_handler = catchint;

  sigfillset(&(act.sa_mask));

  sigaction(SIGTSTP, &act, NULL);

  int i = 0;
  
  while(1){
    printf("Hello World! No = %d\n", i);
    i++;
    sleep(1);
  }

  exit(0);
}

void catchint(int signo){
  
  printf("\n CATCHINT: count = %d\n", count++);
  printf(" CATCHINT: returning\n\n");
  
}
