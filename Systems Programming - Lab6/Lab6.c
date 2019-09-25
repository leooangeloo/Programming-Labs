/*
Title: Lab6.c
Author: Leo Genota
Date: March 29, 2019
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
  char * args[] = {"P3", NULL};
  int status, child_status;
  pid_t pid, c_pid;

  pid = fork();

  if(pid < 0)
    perror("pid error\n");
  else if(pid != 0){ //Parent process
    wait(&status);
    execv("/home/usp/Documents/Lab6/p3", args);
  }
  else{
    c_pid = fork();
    switch(c_pid){
    case -1:
      perror("c_pid error");
      break;
    case 0: //Child process
      execl("/home/usp/Documents/Lab6/p1", "P1", NULL);
      break;
    default:
      wait(&child_status);
      execl("/home/usp/Documents/Lab6/p2", "P2", NULL);
      break;
    }
  }

  return(0);
}
