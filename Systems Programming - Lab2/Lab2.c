#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//#include<sys/types.h>
//#include<sys/stat.h>
#include<fcntl.h>
#define BUFFSIZE 15

int main(){
  char buf[BUFFSIZE];
  int fd,exp_char;
  int n_read;
  
  n_read=read(0,buf,BUFFSIZE);
  printf("return number from the open function is:%d\n",n_read);
  
  if(n_read<= BUFFSIZE){
    printf("%s\n",buf);
  }else{
    printf("%s\n",buf);
  }//end of if
  
  /* open file */
  fd=open("myfile.txt", O_WRONLY |O_CREAT|O_TRUNC,0644);
  if(fd==-1)
    {
      printf("Fail to open\n");
      exit(1);
    }else
    write(fd, buf,n_read);
  
  close(fd);
  exit(0);
}
