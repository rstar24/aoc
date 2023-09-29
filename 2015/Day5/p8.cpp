#include <bits/stdc++.h>
using namespace std;
//Solved

int rule1(string s1);
int rule2(string s1);
int rule3(string s1);

int main(){
    cout<< "Sovling the nice string problem"<<endl;
    ifstream myinput;
    string s1("/home/rishabh/mycode/aoc/2015/Day5/input.txt");
    myinput.open(s1);
    if(!myinput.is_open()){
        cout <<"Error in opening the file"<<endl;
    }
    string l1;
    int f_i=-1;
    while (!myinput.eof())
    {
        getline(myinput,l1);
        f_i++;
    }
    cout << "Number of line :"<<f_i <<endl;

    myinput.clear();
    myinput.seekg(0,std::ios::beg);
    int main_counter= 0;
    for(int i = 0 ;i < 1000 ; i++){
        string ss1;
        getline(myinput,ss1);
        int x= rule1(ss1);
        int y= rule2(ss1);
        int z= rule3(ss1);
        if( ((x && y) && z)){
            main_counter++;
        }
    }
    cout << "The solution is : " << main_counter <<endl;
    myinput.close();
    return 0;
}

int rule1(string s1){
    int flag =0;
    int a=0;
    int e=0;
    int i_r=0;
    int o=0;
    int u=0;
    for(int i =0 ; i < s1.length();i++){
        if(s1[i]=='a'){
            a++;
        }
        else if(s1[i]=='e'){
            e++;
        }
        else if(s1[i]=='i'){
            i_r++;
        }
        else if(s1[i]=='o'){
            o++;
        }
        else if(s1[i]=='u'){
            u++;
        }
    }
    if((a>=3) || (e>=3) || (u>=3) || (o>=3) || (i_r>=3) ||(a+e+i_r+o+u >=3)){
        flag++;
    }
    return flag;
}

int rule2(string s1){
    int flag = 0;
    for(int i =0 ;i < s1.length() ; i++){
        if (s1[i]==s1[i+1]){
            flag = 1;
            break;
        }
    }
    return flag;
}

int rule3(string s1){
    int flag = 0;
    for(int i =0 ; i < s1.length() ; i++){
        if((s1[i]=='a') && (s1[i+1]=='b')){
            flag=0;
            break;
        }
        else if((s1[i]=='c') && (s1[i+1]=='d')){
            flag = 0;
            break;
        }
        else if((s1[i]=='p') && (s1[i+1]=='q')){
            flag = 0;
            break;
        }
        else if((s1[i]=='x') && (s1[i+1]=='y')){
            flag = 0;
            break;
        }
        else{
            flag = 1;
        }
    }
    return flag;
}