/*
Title: Lab9.c
Author: Leo Genota
Date: April 29, 2019
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<signal.h>
int ntimes = 0;

int main() 
{
    int pid;
    void p_action(int, siginfo_t *, void *); 
    void catchint(int); 
    struct sigaction pact, cact, act; 
    pact.sa_sigaction=&p_action;//set up SIGUSR1 action for parent
    
    /* The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not 
       sa_handler. */ 
    // Specify that we will use a signal handler that takes three arguments 
    pact.sa_flags = SA_SIGINFO; 
    sigaction(SIGUSR2, &pact, NULL);//Register a signal SIGUSR2

    act.sa_handler=&catchint;
    sigaction(SIGTSTP, &act, NULL);
    
    // print a parent PID 
     switch(pid=fork()) 
    { 
        case -1: 
            perror("Failedto fork\n"); 
            exit(1); 
        case 0:  //child
	    //your code 
            //set action for child
	  cact.sa_sigaction=&p_action;
            //set up SIGUSR1 action for parent
	  cact.sa_flags = SA_SIGINFO;
            //Register a signal SIGUSR1
	  sigaction(SIGUSR1, &cact, NULL);
	  
            // get parent PID and print
	  printf("%d is parent of child %d\n", getppid(), getpid());
	  
            for( ; ;) 
            {
	      kill(getppid(), SIGUSR2);
	      pause();
	      sleep(1);
            } 
    }//end of switch 

    for( ; ;) { 
       pause();
       sleep(1);
       kill(pid, SIGUSR1);
    }
	
    return 0; 
}

void p_action(int sig, siginfo_t *info, void *ptr) 
{ 
   if (sig == SIGUSR2){ 
      printf("Parent: Received: signal SIGUSR2 (%d) from child %d process\n", sig, (long) info->si_pid); 
      printf("Child caught signal #%d times\n", ++ntimes); 
    }
   else if(sig == SIGUSR1){
     printf("Child: Received: signal SIGUSR1 (%d) from parent %d process\n", sig, (long) info->si_pid);
     printf("Parent caught signal #%d times\n", ++ntimes);
   }
} 

void catchint(int signo) 
{ 
  printf("The signal SIGTSTP has been caught\n");
} 
