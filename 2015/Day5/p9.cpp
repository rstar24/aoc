#include <bits/stdc++.h>
using namespace std;
//Day 5 part 2
//Solved on my own mostly

//void test();
int rule1(string s1);
int rule2(string s1);
void patterns(string s1[]);
//I know that from optimization
//pov this looks bad May be you can suggest changes
//open a pr if you are very 
//annoyed by the preformance
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
    cout << "Number of line : "<<f_i <<endl;

    myinput.clear();
    myinput.seekg(0,std::ios::beg);
    int main_counter= 0;
    

    for(int i = 0; i < 1000; i++){
        string l1;
        getline(myinput,l1);
        int x = rule1(l1);
        int y = rule2(l1);
        if(x&&y){
            main_counter++;
        }
        
    }
    int flag = 0;
    string s_1("tstwsswswrxlzrqs");
    if((rule1(s_1)&& rule2(s_1))){
        flag =1 ;
    }
    
    cout << "The solution is : " << main_counter<<endl;
    
    myinput.close();
    return 0;
}

int rule1(string s1){
    int flag = 0;
    string ss1[676];
    patterns(ss1);
    for(int i =0 ; i < 676 ; i++){
        size_t found = s1.find(ss1[i]);
        size_t again = s1.find(ss1[i],found+2);
        if (again != string::npos){
            flag = 1;
        }
    }
    return flag;
}

int rule2(string s1){
    int flag = 0;
    for(int i =0 ;i < s1.length()-2 ; i++){
        if ((s1[i]==s1[i+2])){
            flag = 1;
            break;
        }
    }
    
    return flag;
}

void patterns(string s1[]){
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
}

