#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc , char *argv[]){
    char ch;
    char ch1[100];
    memset(ch1,'\0',100);
    memset(ch1,'X',20);
    scanf("%c",&ch);
    printf("Not 0 if it is  digit :  %d\n",isdigit(ch));
    printf("Not 0 if it is cntrl : %d\n",iscntrl(ch));
    printf("%s\n",ch1);

    
    return EXIT_SUCCESS;
}