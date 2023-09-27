#include <bits/stdc++.h>
#include </home/rishabh/mycode/aoc/2015/Day4/md5.h>
using namespace std;

#define MAX_SIZE 1000000
//Copied the md5 checksum function from the zedwood.com

int main(int argc, char *argv[]) {
  cout << "Implementing the openssl library function" << endl;
  string s1("abcdef609043");
  string s2("pqrstuv1048970");
  cout << s1 << ": " << md5(s1) << endl;
  cout << s2 <<": "<< md5(s2) << endl;
  string s3("/home/rishabh/mycode/aoc/2015/Day4/input.txt");
  
  ifstream myinput;
  myinput.open(s3);
  string s4;
  char ch;
  if(!myinput.is_open()){
    cout<< "Error on opening the file"<<endl ;
  }
  cout << "My Input is : " ;
  getline(myinput,s4);
  cout <<s4 <<endl;
  int gi=0;
  long int k=0;  
  int flag = 0;
  
  for(int i = 0 ;i < MAX_SIZE ;i++){
    string ss1;
    string ss2;
    ss1=s4;
    string temp;
    temp = to_string(k);
    ss1.append(temp);
    ss2 = md5(ss1);
    for(int i = 0; i < 5; i++){
      if(
        (ss2[0]=='0') &&
        (ss2[1]=='0') &&
        (ss2[2]=='0') &&
        (ss2[3]=='0') &&
        (ss2[4]=='0') 
      ){
        flag = 1;
      }
    }
    if (flag==1){
      cout << ss2 << endl;
      cout<< "solution :" << k <<endl;
      break;
    }
    k++;
  }
  cout << endl;

  return 0;
}