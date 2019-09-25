/*
 *Title: Lab4.c
 *Created on: Feb 22, 2019
 *Author: Leo Genota
 */
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

void lab4(char * filein, char * fileout, int rep);

int main(int ac, char*argv[])
{
  int n;
  if(ac>1)
   {
      printf("Enter the number you want to skip\n:");
      scanf("%d",&n);
      lab4(argv[1],argv[2],n);//function call
      printf("\n");
   }
  else
    printf("There is an argument error\n");

  exit(0);
}
void lab4(char *filein, char *fileout, int rep)
{
  int fd1, fd2, count = 0;//counter of chars
  //opens the in/out files 
  fd1 = open (filein, O_RDONLY,0644);
  fd2 = open (fileout, O_CREAT|O_RDWR|O_TRUNC,0644); 
  char tmp;

  //error handling for the files
  if (fd1 == -1 || fd2 == -1)
  {
     perror("Could not open files");
     exit(1);
  }

   while(read(fd1, &tmp, 1) > 0)
   {
     lseek(fd1, 0, SEEK_CUR);
     count++;
   }

  
  lseek(fd1, rep, SEEK_SET);
  
  while(read(fd1,&tmp,1) > 0)
  // reads one char at a time
  {
    write(fd2,&tmp,1);
    // writes one char at a time
    lseek(fd1,rep,SEEK_CUR);//seeks position
  }

   //handles error no char to read
   if(count == 0){
     printf("There are no characters to read\n");
   }

  //prints out counter of chars
  printf("No of Characters: %d\n", count);
  close(fd1);
  close(fd2);
}
