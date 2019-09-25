/*
 *Title: ASs1.c
 *Created On: February 12, 2019
 *Author: Leo Genota
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFSIZE 15
int main(){
 char buf[BUFFSIZE];
 char buf2[BUFFSIZE];
 int fd, n_read, counter = 0;
 int ret;

 //FILE DESCRIPTOR TO OPEN FILE
 fd = open("myfile.txt", O_RDONLY);

 //DO-WHILE LOOP TO PRINT FILE TO SCREEN
 do{
  ret = read(fd, buf2, 100);

  //ERROR HANDLING CODE
  if(fd == -1)
   perror("open");
  else
   buf2[ret] = '\0';

  //PRINTS BUFFER TO SCREEN
  printf("%s\n", buf2);
 }while(ret >0);
 //END DO-WHILE

 close(fd);

 //OPENS NEW FILE DESCRIPTORS
 fd = open("myfile.txt", O_RDONLY);
 n_read = read(fd, buf, BUFFSIZE);

 //ERROR HANDLING CODE
 if(fd == -1)
  perror("open");
 else
  buf[n_read] = '\0';

 //PRINTS BUFFER CONTENTS
 printf("return number from the open function is:%d\n", n_read);

 //IF N_READ LT BUFFSIZE, PRINT
 if(n_read <= BUFFSIZE)
  printf("%s\n", buf);

 //WHILE LOOP TO PRINT OUT FILE CONTENTS PER BUFFSIZE
 while(BUFFSIZE == n_read){
  counter = counter + n_read;//KEEPS COUNTER;
  n_read = read(fd, buf, BUFFSIZE);

  printf("return number from the open function is:%d\n", n_read);

  //ERROR HANDLING CODE
  if(fd == -1)
   perror("open");
  else
   buf[n_read] = '\0';

  if(n_read <= BUFFSIZE)
   printf("%s\n", buf);
 }

 counter = counter + n_read;
 //PRINTS OUT COUNTER OF CHARACTERS
 printf("Total number of characters: %d\n", counter);
 buf[n_read] = '\0';
 close(fd);
 exit(0);
}
