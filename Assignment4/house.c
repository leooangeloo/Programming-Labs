/*
Title: house.c (Assignment 4)
Author: Leo Genota
Date: April 8, 2019
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  char * args[] = {"P3", NULL};
  int status, child_status, status2, child_status2;
  pid_t pid, c_pid, pid2, c_pid2;

  pid = fork();

  if(pid < 0) //Error handling
    perror("pid error\n");
  else if(pid != 0){ //Parent process
    wait(&status);
    //Calls program p3 which displays base of building
    execv("/home/usp/Documents/Ass4/p3", args);
  }
  else{ //Child process
    c_pid = fork();
    
    switch(c_pid){
    case -1: //Error handling
      perror("c_pid error");
      break;
    case 0: //Child process
      pid2 = fork();
      if(pid2 < 0) //Error handling
	perror("pid2 error\n");
      else if(pid2 != 0){
	wait(&status2);
	//Calls program p3 which displays base of building
        execv("/home/usp/Documents/Ass4/p3", args);
      }
      else{ //Child process
	c_pid2 = fork();
	switch(c_pid2){
	case -1:
	  perror("c_pid error");
	  break;
	case 0://
	  //Calls program p1 to print the roof of house
	  execl("/home/usp/Documents/Ass4/p1", "P1", NULL);
	  break;
	default:
	  wait(&child_status2);
	  //Calls program p2 to print the middle struct of house
	  execl("/home/usp/Documents/Ass4/p2", "P2", NULL);
	  break;
	}//End of switch(c_pid2)
      }//End of else (inner)
    default:
      wait(&child_status);
      //Calls program p2 to print the middle struct of house
      execl("/home/usp/Documents/Ass4/p2", "P2", NULL);
      break;
    }//End of else (outer)
  }

  return(0);
}
