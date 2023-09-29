#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc , char *argv[]){
    
    char ch[] = "This 1234 test";
    int n = sizeof(ch)/ sizeof(ch[0]);
    for(int i = 0 ; i < n ; i++){
        int x = isalnum(ch[i]);
        printf("%d\n",x);
    }
    
    
    return EXIT_SUCCESS;
}