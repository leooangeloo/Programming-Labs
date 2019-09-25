/*
Title: Lab8.c
Author: Leo Genota
Date: April 28, 2019
 */

//libraries for the program
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<signal.h>

//defines num of children
#define N 5


int main(){
  void sigchld_handler(int);
  static struct sigaction act;
  
  int child, cpid;
  printf("Creating %d children\n", N);
  printf("Parent = %d\n", getpid());

    for(int i=0;i<N;i++) // loop will run n times (n=5) 
    {
      child = fork();
      
      switch(child){
      case 0: //for child
	//necessary statements for sigaction()
	act.sa_handler = sigchld_handler;
	sigfillset(&(act.sa_mask));
	printf("[Child] pid = %d [Parent] pid = %d\n", getpid(), getppid());
	sigaction(SIGINT, &act, NULL);
	return 0;
	break;
      case -1: //for error handling
	perror("switch");
	break;
      }
    }//end of for 
    // Wait until all children are terminated. 
     for(int i=0; i<N; i++) 
     {
       wait(NULL);
     } 
    printf("Parent terminate\n");

    return 0;
}

void sigchld_handler(int signo) 
{  
    printf("SIGCHILD caught\n");
    printf("%d is dead\n", signo);
}
