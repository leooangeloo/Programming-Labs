/* 
Author: Leo Genota
Title: Lab10.c
Date: May 10, 2019
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/wait.h>

#define MSGSIZE 6
#define NPIPES 2
#define temp 4
#define ever ;;

char *msg1 = "Hello!";
char *msg3 = "Bye!";

int fatal(char *s)
{
  perror(s);
  exit(1);
}

int parent(int p[][2]);
int child(int pfd[]);

int main()
{
  int pfd[NPIPES][2]; //file descriptors for three pipes
  int i;

  for(i = 0; i < NPIPES; i++)
    {
      if(pipe(pfd[i]) == -1)
	{

	  fatal("Pipe call");
	  exit(1);

	}

      switch(fork())
	{
	case (pid_t) -1: //fork failed
	  
	  fatal("Pipe call");
	  exit(1);
	  
	case 0: //child process
	  child(pfd[i]);
	} //end of switch statement
    } //end of for loop

  parent(pfd); //parent will monitor all three pipes and stdin

  return 0;
} //end of main


int parent(int p[NPIPES][2]) //function for parent process
{
  struct timeval timeout;
  timeout.tv_sec = 5;
  timeout.tv_usec = 0;
  char buf[MSGSIZE], ch;

  fd_set tset, master; //data struct needed for select

  int i;

  //close file descriptors for the write-ends of pipes.

  for(i = 0; i < NPIPES; i++)
    {
      
      if(close(p[i][1]) == -1)
	{
	  fprintf(stderr, "Parent: Couldn't close write end of pipe %d.\n", i);
	  exit(1);
	}
    }

  FD_ZERO(&master);
  FD_SET(STDIN_FILENO, &master); //parent watches stdin and read-ends of three pipes.

  for(i = 0; i < NPIPES; i++)
    FD_SET(p[i][0], &master);

  /*Parent calls select without timeout. So, parent will block until
    and event occurs. We need to remember the master bit mask since select
    will change the mask.*/

  tset = master;

  /*The number of filer descriptors must include stdin*/

  while(select(p[NPIPES - 1][0] + 1, &tset, NULL, NULL, &timeout) > 0)
    {
      if(FD_ISSET(STDIN_FILENO, &tset)) //check if stdin has any data and print it
	{
	  printf("From stdin: ");
	  read(STDIN_FILENO, &ch, 1);
	  printf("%c\n", ch);
	}

      //Check if any of the pipes have data and print the data.

      for(i = 0; i < NPIPES; i++)
	{
	  if(FD_ISSET(p[i][0], &tset))
	    {
	      if(read(p[i][0], buf, MSGSIZE) > 0)
		printf("Message from child %d: %s\n", i, buf);
	    } //end of if statement
	} //end of for loop


      if(waitpid(-1, NULL, WNOHANG) == -1)
	return 0;

      tset = master;
    }

  printf("Timeout\n");

  return 0;
} //end of parent function



int child (int p[])
{
  /*Code for each child process. Each child process writes two messages
    with a different waiting time between the messages and quits.*/

  int count;

  if(close(p[0] == -1))
    {

      fprintf(stderr, "Child: Couldn't close read end of pipe.\n");
      exit(1);

    }


  for(count = 0; count < 2; count++)
    {
      write(p[1], msg1, MSGSIZE);
      sleep(getpid()%temp);
    }

  
    //code to send message through the pipe
    //send first message to the parent process NUM_MSG times
    //sleep after writing the first message
    //you can use the random amount of time for sleep as getpid()%temp

  write(p[1], msg3, MSGSIZE);
  sleep(1);

  //send final message once
    exit(0);
}
