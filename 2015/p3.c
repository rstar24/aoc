#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  //opening The file
  FILE *fp = fopen("/home/rishabh/mycode/aoc/2015/p3-inputc.txt","r");
  if(fp == NULL){
    printf("There was a error opening the file\n");
    exit(1);
  }
  int i=0;
  int sum ;
  //counting the lines
  do{
    char str1[10];
    fgets(str1,10,fp);
    if(!feof(fp)){
      i++;
    }
  }
  while (!feof(fp)) ;
  
  // Only one-d array  for storing dimensions
  // of the cubes
  long int dim[3000];
  long int area[1000];
  long int total;
  long int lw;
  long int wh;
  long int hl;
  long int sa;
  //The file pointer rewind
  rewind(fp);
  // To read each dimensions of the a cubes
  int ix=0;
  long  num;
  do {
    if(!feof(fp)){
      char z[3];
      char *endpt;
      fgets(z,3,fp);
      num = strtol(z,&endpt,10);
      //printf("%ld\n",num);
    }
    if(num != 0){
      dim[ix] = num;
      ix++;
    }
  } while(!feof(fp));
  //to see all the dimensions
  /*
  for(int i= 0; i < 3000; i++){
    printf("%ld\n",dim[i]);
  }
  */
  
  for (int i=0;i< 1000;i++) {
    long int lw = (dim[(i*3)]) * (dim[((i*3)+1)]);
    long int wh = (dim[(i*3)+1]) * (dim[((i*3)+2)]);
    long int hl = (dim[(i*3)+2]) * (dim[(i*3)]);
    long int sa = ((2*lw) + (2 * wh) + (2*hl));
    long int shorta = (((lw>wh) ? wh:lw) > hl ? hl : ((lw>wh) ? wh:lw)); 
    area[i] = sa + shorta;
  }
  for(int i=0; i<1000;i++){
    printf("%ld\n",area[i]);
  }
  
  for(int i =0; i< 3000; i++){
    total =total + area[i] ;
  }
  
  printf("This is number of cubes :%d\n",i);
  printf("The total area of paper require : %ld\n",total);
  system("fortune | lolcat");
  return EXIT_SUCCESS;
}
