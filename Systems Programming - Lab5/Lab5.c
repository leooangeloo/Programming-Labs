/*
 * Lab5.c
 *
 *  Created on: Mar 1, 2019
 *      Author: Leo Genota
 */
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<time.h>
#include<string.h>

void show_stat_info(char * fname, struct stat * buf);

int main(int argc, char *argv[]){
  struct stat sb;

  //Error handling for argc < 2
  if (argc < 2) 
  {
    printf("Your input argument is not valid. Try again!\n");
      fprintf (stderr,"usage: %s <file>\n", argv[0]);
      exit(1);
  }
  //Error handling for unknown file status
  if (stat(argv[1], &sb) == -1)
  {
      perror("Failed to get file status");
      exit(1);
  }
  else{
    //Print out file stat information
     printf("%s accessed: %s modified: %s", argv[1],
	    ctime(&sb.st_atime), ctime(&sb.st_mtime));
     //Call to function to display file stat
     show_stat_info(argv[1], &sb);
  }
  exit(0);
}

void show_stat_info(char * fname, struct stat * buf){
  
  printf(" size: %d\n", buf->st_size); //Displays file size
  printf(" file type: "); //Displays file type
  //Switch statement to determine file type
   switch (buf->st_mode & S_IFMT) 
    {
    case S_IFBLK:
      printf("block device node\n");
      break;
    case S_IFCHR:
      printf("character device node\n");
      break;
    case S_IFDIR:
      printf("directory\n");
      break;
    case S_IFIFO:
      printf("FIFO\n");
      break;
    case S_IFLNK:
      printf("symbolic link\n");
      break;
    case S_IFREG:
      printf("regular file\n");
      break;
    case S_IFSOCK:
      printf("socket\n");
      break;
    default:
      printf("unknown\n");
      break;
    }
   printf(" mode: %d\n", buf->st_mode); //Displays file mode
   printf(" links: %d\n", buf->st_nlink); //Displays file link #
   printf(" userid: %d\n", buf->st_uid); //Displays file userid
}
