#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fp = fopen("/home/rishabh/mycode/aoc/2015/p3-input.txt","r");
  if(fp == NULL){
    printf("There was a error opening the file\n");
    exit(1);
  }
  int i=0;

  do{
    char str1[10];
    i++;
    if(i){
    printf("%s",str1); 
    }
    fgets(str1,10,fp);
    if(str1)
  }
  while (!feof(fp)) ;

  printf("The total number of character :%d\n",i);

  return EXIT_SUCCESS;
}
