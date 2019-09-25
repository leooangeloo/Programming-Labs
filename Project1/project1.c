/*
Author: Leo Angelo Genota
Due: March 28, 2019
This program implements a Hotel Reservation system
 */
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>
#define NAMELENGTH 11
#define NROOMS 10

char namebuf[NAMELENGTH];
int infile = -1;

void menu();
void menuRet(int choice);
void listRooms();
void checkIn(int rmNo, char * occupant);
void checkOut(int rmNo);

int main(){
 int c;
 
 //opens to display user menu
 menu();

 //loop thru menu for user
 while(c != 4){
  printf("----------------------------------\n");
  printf("Enter a menu (1, 2, 3, 4): ");
  scanf("%d/n", &c); 
  menuRet(c);  
 }
 return 0;
}

//-----MENU Function
void menu(){
 printf("===============\n");
 printf("1. List of rooms\n");
 printf("2. Check-in\n");
 printf("3. Check-out\n");
 printf("4. Quit\n");
 printf("===============\n");
}

//-----MENURET Function
void menuRet(int choice){
 int c;
 char * name, *getoccupier(int), *p;

 if(choice == 1)
  listRooms();
 else if(choice == 2){
  printf("Enter the room for checking-in: ");
  scanf("%d", &c);

  if(c >= 1 && c <= 10){
   p = getoccupier(c);
   if(p[0] == ' '){
    printf("Enter the name of the occupant: ");
    scanf("%s", name);
    if(strlen(name) <= 10){
     checkIn(c, name);
     printf("%s has been checked into room %d. Enjoy!\n", name, c);
    }
    else{
     printf("--> The entered name is longer than 10 chars.\n");
    }
   }
   else{
    printf("The room is currently occupied. \n");
   }//end of inner if statement
  }
  else{
   printf("--> The entered item (%d) is not valid! \n", c);
  }//end of outer if statement
 }//end of if statement for choice 2
 else if(choice == 3){
  printf("Enter the room number for checking-out: ");
  scanf("%d", &c);

  if(c >= 1 && c <= 10){
   checkOut(c);
   printf("You have been successfully checked out. \n");
   printf("Room %d is now available for check-in. \n", c);
   printf("Thank you for staying with us. Come again soon! \n");
  }
  else{
   printf("--> The entered item (%d) is not valid! \n", c);
  }//end of inner if statement
 }//end of if statement for choice 3
 else if(choice == 4){ 
  printf("Goodbye!!\n");
  exit(0);
 }//end of if statement for choice 4 
 else{
  //error-handling for entered menu item
  printf("--> The entered menu (%d) is not valid!\n", choice);
  exit(1);
 }//end of if statement for invalid choice
}

//-----GETOCCUPIER Function
char *getoccupier(int roomNo){
 off_t offset;
 ssize_t nread;
 
 if(infile == -1 && (infile = open("residents.txt", O_RDONLY)) == -1){
  return(NULL);
 }
 
 offset = (roomNo - 1) * NAMELENGTH;

 if(lseek(infile, offset, SEEK_SET) == -1)
  return(NULL);
 
 if((nread = read(infile, namebuf, NAMELENGTH)) <= 0)
  return(NULL);

 namebuf[nread - 1] = '\0';
 return(namebuf);
}

//-----LISTROOMS Function
void listRooms(){
 int j;
 char *getoccupier(int), *p;

 //for-loop to list room# and names of occupants 
 for(j = 1; j <= NROOMS; j++){
  if(p = getoccupier(j))
   printf("Room %d, %s\n", j, p);
  else
   printf("Error on room %d\n", j);
 }
}

//-----CHECK-IN Function
void checkIn(int rmNo, char * occupant){
 int nwrite;
 char *getoccupier(int), *p;
 
 //re-calls file and re-writes list with added occupant
 int fd = open("residents.txt", O_CREAT | O_WRONLY | O_TRUNC & O_APPEND, 0644);

 //for-loop to write the names to the file
 for(int j = 1; j < NROOMS+1; j++){
  if((p=getoccupier(j)) && j == rmNo){
   nwrite = write(fd, occupant, NAMELENGTH - 1);
  }
  else
   nwrite = write(fd, p, NAMELENGTH - 1);
   
   nwrite = write(fd, "\n", 1);
 }
}

//-----CHECK-OUT Function 
void checkOut(int rmNo){
 int nwrite;
 char *getoccupier(int), *p;
 
 //re-calls file and re-writes list with deleted occupant
 int fd = open("residents.txt", O_CREAT | O_WRONLY | O_TRUNC & O_APPEND, 0644);

 //for-loop to write the names to the file
 for(int j = 1; j < NROOMS+1; j++){
  if((p=getoccupier(j)) && j == rmNo)
   nwrite = write(fd, "           ", NAMELENGTH - 1);
  else
   nwrite = write(fd, p, NAMELENGTH - 1);
   
   nwrite = write(fd, "\n", 1);
 }
}
 
