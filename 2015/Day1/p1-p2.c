#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ADVENT OF CODE PUZZLE 1 OF 2015
// TRIED ON 2023-06-29

// SOLVED AGAIN 2023-08-24 16:15

int main() {

  FILE *fp = fopen("/home/rishabh/mycode/aoc/2015/Day1/input.txt", "r");
  if (fp == NULL) {
    printf("Failed to open the FIle\n");
  }

  int count = 0;
  int total = 0;
  int ch;
  int pos;
  int ex = 0;

  while ((ch = (fgetc(fp))) != EOF) {
    char x = (char)ch; // Because fgetc return int

    if (total == -1) {
      if (!ex) {
        pos = count;
        ex++;
      }
    }

    if (x == '(') {
      total++;
    } else if (x == ')') {
      total--;
    }
    count++;
  }

  printf("Number of Characters in file : %d \n", count);
  printf("Number of Floor where Santa is : %d\n", total);
  printf("First position of character when santa is in basement : %d\n", pos);
  printf("File Ends here : %d\n", ((fgetc(fp))));
  system("fortune | lolcat");
  // TODO Solve by using the dynamic array
  // I will return for refactoring the code more

  return 0;
}
/*The files in the directory
 */
