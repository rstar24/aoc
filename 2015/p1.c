#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// advent of code puzzle 1 of 2015
// tried on 2023-06-29

// Make a Function to count the 
// file characters


int main() {

  FILE *fp = fopen("/home/rishabh/mycode/aoc/2015/input.txt", "r");
  FILE *T;
  if (fp == NULL){
    printf("Failed to open the FIle\n");
  }
  
  int count = 0;
  char ch;
  while((ch = fgetc(fp)) != EOF){
    printf("%c",ch);
    count++;

  }
  printf("Number of Characters in file : %d \n", count);
  char s = fgetc(T);
  printf("%s\n",s);
  //int s = fgetc(t);
  //printf("%d \n",s);
  return 0;
}
