#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp = fopen("/home/rishabh/mycode/aoc/2015/Day3/input.txt", "r");
  if (fp == NULL) {
    printf("There was an error opening file\n");
  }
  int i = 0;
  while (!feof(fp)) {
    int ch = fgetc(fp);
    if (!feof(fp)) {
      printf("%c", ch);
      i++;
    }
  }
  printf("%d\n", i);

  return EXIT_SUCCESS;
}
