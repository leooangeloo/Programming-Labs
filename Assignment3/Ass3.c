/*
Title: Ass3.c
Author: Leo Genota
Date: April 2, 2019
This program implements 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<time.h>
#define MFILE  1 //number of files to be monitored 

time_t last_atime; 
time_t last_mtime; 
time_t last_ctime;
time_t last_mode;
time_t last_size;
time_t last_nlinks;
time_t last_blocks;

void cmp(char *, time_t); 
struct stat sb;

void file_update(char * name);
void file_monitor(char * name);

int main(int ac, char *argv[]) 
{ 
  int j; 
  int i=0;
  int status;
  time_t last_time[MFILE+1];
  

  pid_t pid;
  
  if(ac<2) 
  { 
    fprintf(stderr,"Failed to lookout:\n"); 
    exit(1); 
  }
  
  if(--ac>MFILE) 
  { 
    fprintf(stderr,"Too many filenames:\n"); 
    exit(1); 
  }
  
  for(j=1;j<=ac;j++) 
  { 
    if(stat(argv[j], &sb) ==-1) 
    { 
      fprintf(stderr,"Failed to stat:%s\n",argv[j]); 
      exit(1); 
    }
    last_mtime=sb.st_mtime;
    last_atime=sb.st_atime;
    last_ctime=sb.st_ctime;
    last_mode=sb.st_mode;
    last_size=sb.st_size;
    last_nlinks=sb.st_nlink;
    last_blocks=sb.st_blocks;
    
    
    
  }//end of for  j
  
  pid = fork();
  if(pid < 0){
    perror("Error in pid = fork() \n");
    exit(1);
  }
  else if(pid == 0){
    //CHILD PROCESS
    file_update(argv[1]);
  }
  else{
    //PARENT PROCESS
    file_monitor(argv[1]);
    pid_t child_pid = wait(&status);
    

    printf("Child %d\n", child_pid);
    printf("Parent %d\n", getpid());
  }

  return 0;
  
} 

void file_update(char * name){
  char * linkedname;
  int i = 1;
  int fd = open(name, O_CREAT | O_WRONLY | O_TRUNC & O_APPEND, 0644);

  while(i <= 36){
    int temp = rand()%4;

    switch(temp){
    case 0 :
      chmod(name, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH);
      break;
    case 1 :
      write(fd, "This is COSC 430 Assignment 3 programming\n", 42);
      break;
    case 2 :
      sprintf(linkedname, "myfile%1d.txt", rand()%5);
      link(name, linkedname);
      break;
    case 3 :
      sprintf(linkedname, "linkedfile%ld.txt", rand()%5); // generate a random name.  
      unlink(linkedname); // unlink
      break;
    }
    sleep(5);
    i++;
  }
}
void file_monitor(char * name){
  int i = 1;

  while(i <= 36 * 1.5){
    if(stat(name, &sb) == -1){
      perror("Failed to get file status.\n");
      exit(1);
    }
    else{
      printf("------------Updated Status-------------\n");
      if(sb.st_mode != last_mode){
	printf(" mode change from: %o to %o\n", last_mode, sb.st_mode); //Displays file mode
	last_mode = sb.st_mode;
      }
      if(sb.st_size != last_size){
	printf(" size change from: %d bytes to %d bytes\n", last_size, sb.st_size); //Displays file size
	last_size = sb.st_size;
      }
      if(sb.st_atime != last_atime){
	printf(" last file access: %s\n", ctime(&sb.st_atime));
	last_atime = sb.st_atime;
      }
      if(sb.st_mtime != last_mtime){
	printf(" last file modification: %s\n", ctime(&sb.st_mtime));
	last_mtime = sb.st_mtime;
      }
      if(sb.st_ctime != last_ctime){
	printf(" ctime: %s", ctime(&sb.st_ctime));
	last_ctime = sb.st_ctime;
      }
      if(sb.st_nlink != last_nlinks){
	printf(" links change from: %d to %d\n", last_nlinks, sb.st_nlink); //Displays file link #
	last_nlinks = sb.st_nlink;
      }
      if(sb.st_blocks != last_blocks){
	printf(" blocks change from: %d to %d\n", last_blocks, sb.st_blocks); //Displays num of blocks allocated
	last_blocks = sb.st_blocks;
      }
      printf("\n");
    }
    sleep(1);
    i++;
  }
}

/*

st_mode 

st_size 

st_atime 

st_mtime 

st_ctime 

st_nlinks 

st_blocks 

time_t last_atime; 
time_t last_mtime; 
time_t last_ctime;
time_t last_mode;
time_t last_size;
time_t last_nlinks;
time_t last_blocks;



*/
