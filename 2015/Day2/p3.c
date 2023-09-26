#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long ribln(long a, long b, long c);
long volume(long a, long b, long c);

int main(int argc, char *argv[]) {
  // opening The file
  FILE *fp = fopen("/home/rishabh/mycode/aoc/2015/Day2/p3-inputc.txt", "r");
  if (fp == NULL) {
    printf("There was a error opening the file\n");
    exit(1);
  }
  int i = 0;
  int sum;
  // counting the lines
  do {
    char str1[10];
    fgets(str1, 10, fp);
    if (!feof(fp)) {
      i++;
    }
  } while (!feof(fp));

  // Only one-d array  for storing dimensions
  // of the cubes
  long int dim[3000];
  long int area[1000];
  long int l[1000];
  long int w[1000];
  long int h[1000];
  long long int rbl[1000];
  long int total;
  long long int trb;
  long long int trb2;
  long int lw;
  long int wh;
  long int hl;
  long int sa;
  // The file pointer rewind
  rewind(fp);
  // To read each dimensions of the a cubes
  int ix = 0;
  long num;
  do {
    if (!feof(fp)) {
      char z[3];
      char *endpt;
      fgets(z, 3, fp);
      num = strtol(z, &endpt, 10);
      // printf("%ld\n",num);
    }
    if (num != 0) {
      dim[ix] = num;
      ix++;
    }
  } while (!feof(fp));
  // to see all the dimensions
  // For the part two of the puzzle
  for (int i = 0; i < 1000; i++) {
    l[i] = (dim[i * 3]);
    w[i] = (dim[(i * 3) + 1]);
    h[i] = (dim[(i * 3) + 2]);
  }
  // calculate the ribbon length
  for (int i = 0; i < 1000; i++) {
    long long int x = ribln(l[i], w[i], h[i]);
    long long int y = volume(l[i], w[i], h[i]);
    rbl[i] = x + y;
  }

  for (int i = 0; i < 1000; i++) {
    long int lw = (dim[(i * 3)]) * (dim[((i * 3) + 1)]);
    long int wh = (dim[(i * 3) + 1]) * (dim[((i * 3) + 2)]);
    long int hl = (dim[(i * 3) + 2]) * (dim[(i * 3)]);
    long int sa = ((2 * lw) + (2 * wh) + (2 * hl));
    long int shorta = (((lw > wh) ? wh : lw) > hl ? hl : ((lw > wh) ? wh : lw));
    area[i] = sa + shorta;
  }
  for (int i = 0; i < 1000; i++) {
    total = total + area[i];
  }
  int kk = 0;
  for (int i = 0; i < 1000; i++) {
    kk = (int)(kk + rbl[i]);
  }
  printf("This is number of cubes :%d\n", 1000);
  printf("The total area of paper require : %ld\n", total);
  printf("The length of ribbon : %d\n", kk);
  system("fortune | lolcat");
  return EXIT_SUCCESS;
}

long int ribln(long int a, long int b, long int c) {
  long int x = 0;
  if (((a >= b) && (a >= c))) {
    x = b + b + c + c;
  } else if (((b >= a) && (b >= c))) {
    x = a + a + c + c;
  } else if (((c >= a) && (c >= b))) {
    x = a + a + b + b;
  }
  return x;
}

long int volume(long int a, long int b, long int c) {
  long int z = a * b * c;
  return z;
}
