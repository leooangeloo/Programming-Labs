#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  char sen[100];
  int num;

  int fd = open("myfile.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
  
  printf("Your input will be entered in myfile.txt \n");
  printf("How many sentences would you like to enter: ");
  //scanf("%d\n", num);
  
  for(int i = 0; i < 4; i++){
    printf("Enter a sentence: \n");
    scanf("%s\n", sen);
    read(fd, sen, 100);
  }
  
  return 0;
}
