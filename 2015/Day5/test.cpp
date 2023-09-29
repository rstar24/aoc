#include <bits/stdc++.h>
using namespace std;
//This file was created for the solution helping part 
int main(){
    string s1[676];
    int x = 97;
    int main_counter=0;

    for(int i = 0 ; i < 26; i++){
        int y = 97;
        char a = (char) x;

        for(int j = 0 ; j < 26 ;j++){
            char b = (char) y;
            string ss1;
            ss1.append(1,a);
            ss1.append(1,b);
            s1[main_counter] = ss1;
            y++;
            main_counter++;
        }
        x++;
    }
    cout << main_counter <<endl;

    for (int i = 0; i < 676; i++)
    {
        cout << s1[i] <<endl;
    }    
    
    return 0;
}


