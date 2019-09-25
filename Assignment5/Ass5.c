/*
Title: Assignment 5 (Group Assignment)
Name: Leo Genota & Isaiah Gregory

This assignment utilizes pipes to communicate between
one parent and two children, performing operations
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<sys/types.h>

int main(){
  int result = 1, result1 = 1, res, r = 0;
  int c1array[] = {1,2,3,4}; //array for child 1's ops
  int c2array[] = {10,20}; //array for child 2's ops
  int fd[2][2]; //create p/c1 pipe
  int fd1[2][2]; //create p/c2 pipe

  for(int i = 0; i < 2; i++){
    if(pipe(fd[i]) == -1) //connecting pipe
      perror("pipe"); //error handling
  }
 
  for(int i = 0; i < 2; i++){
    if(pipe(fd1[i]) == -1) //connecting pipe
      perror("pipe"); //error handling
  }
 
  pid_t pid = fork();
 
  if(pid < 0) //ERROR HANDLING
    perror("pid");
  else if(pid > 0){ //PARENT PROCESS
    int temp;
    int res1;
    close(fd[0][0]);
    size_t n = sizeof(c1array)/sizeof(c1array[0]);

    for(int i = 0; i < n; i++){
      //writes the array to the file descriptor
      write(fd[0][1], &c1array[i], sizeof(c1array[i]));
    }
    printf("Data sent to child 1\n");

    close(fd[0][1]); //closes the write for fd
    wait(NULL); 

    //reads from the file descriptor to res
    read(fd[1][0], &res, sizeof(res));
    close(fd[1][0]);//closes the read for fd

    //creates a new child process for parent
    pid_t pidc = fork();
    
    if(pidc < 0)
      perror("pidc");
    else if(pidc > 0){ //PARENT PROCESS (2)
      close(fd1[0][0]);
      size_t n = sizeof(c2array)/sizeof(c2array[0]);

      for(int i = 0; i < n; i++){
	//writes the array to the file descriptor
	write(fd1[0][1], &c2array[i], sizeof(c2array[i]));
      }
      printf("Data sent to child 2\n");

      close(fd1[0][1]); //closes the write for fd1
      wait(NULL);

      //reads from the file descriptor to res1
      read(fd1[1][0], &res1, sizeof(res1));
      close(fd1[1][0]); //closes the read for fd1
      r = res + res1;

      //displays the operation being done and prints the
      //result of the operations by children and parent
      printf("(%d * %d * %d * %d) + (%d / %d)\n", c1array[0], c1array[1],
	     c1array[2], c1array[3], c2array[1], c2array[0]);
      printf("The result of the processes is: %d\n", r); 
    }
    else{ //CHILD2 PROCESS
      close(fd1[0][1]);
      int val, c, d;

      size_t n = sizeof(c2array)/sizeof(c2array[0]);

      printf("Data -> C: %d, D: %d\n", c2array[0], c2array[1]);

      for(int i = 0; i < n; i++){
	//reads the file descriptor to val
	read(fd1[0][0], &val, sizeof(val));
	if(i == 0) //first value
	  c = val;//assigns val to c if first element
	else //second value
	  d = val;//assigns val to d if second element
      }
      //computation for child2
      result1 = d / c;
      printf("Data divided by child 2\n");

      close(fd1[0][0]);

      //writes from the fd1 to result1
      write(fd1[1][1], &result1, sizeof(result1));
      printf("Data sending back to parent: %d\n", result1);
      printf("\n");
      close(fd1[1][1]);
    }//end of CHILD2
    
  }//end of PARENT (1)
  else{ //CHILD1 PROCESS
    close(fd[0][1]);
    int val;

    size_t n = sizeof(c1array)/sizeof(c1array[0]);

    printf("Data -> A: %d, B: %d, C: %d, D: %d\n",
	   c1array[0], c1array[1], c1array[2], c1array[3]);
  
    for(int i = 0; i < n; i++){
      read(fd[0][0], &val, sizeof(val));
      result = result * val; //calculation by child 1
    }
    printf("Data multiplied by child 1\n");

    close(fd[0][0]);

    //writes fd to the result
    write(fd[1][1], &result, sizeof(result));
    printf("Data sending back to parent: %d\n", result);
    printf("\n");
    close(fd[1][1]);

  }//end of CHILD1

  return 0;
}
