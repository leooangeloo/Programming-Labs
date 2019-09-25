/*
 * Lab3.c
 *
 *  Created on: Feb 18, 2019
 *      This program concatenates two text files together in one file
 *      Author: Leo Angelo Genota
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#define BUFFSIZE 50

void lab3(int fd, int fd1, int fd2){

  char buff[BUFFSIZE], b1[BUFFSIZE];//declare/init buffers
  int n_read, n_read1;//read descriptors

    //reads given files
    n_read = read(fd, buff, BUFFSIZE);
    n_read1 = read(fd1, b1, BUFFSIZE);

    if(fd == -1)
      printf("Fail to open\n");//err-handle code 
    else
      write(fd2,buff,n_read); //line to write to "out"


    if(fd1 == -1)
      printf("Fail to open\n"); //err-handle code
    else
      write(fd2,b1,n_read1); //line to write to "out"  
}

int main(){

  int fd,fd1,fd2; //declares file descriptors

  //opens given files
  fd = open("one.txt",O_RDONLY);
  fd1 = open("two.txt",O_RDONLY);

  //creates a out.txt file, if exists, overwrite
  fd2 = open("out.txt",O_WRONLY|O_CREAT|O_TRUNC, 0644);

  lab3(fd,fd1,fd2);//calls lab3 function

  //closes file descriptors
  close(fd);
  close(fd1);
  close(fd2);
  
  return(0);
}
