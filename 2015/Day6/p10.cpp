#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

//Initializing the matrix setting 
//all the values to -1

void init(int (&G)[1000][1000]);
//Function declaration to read the instruction
//that santa has given to the elf for lights
void readInstruction(string s[], int (&arr)[300][5]);

//Function of to on ,off or toggle the lights
void executeInstruction(int (&arr)[300][5], int (&G)[1000][1000]);

//Check the lights
int checkLights(int (&G)[1000][1000]);


int main() {
  cout << "I am taking way too much time for solving this " << endl;
  int G[1000][1000];
  cout << "Matrix Initialized" << endl;
  init(G);

  //Reading the file 

  ifstream in("/home/rishabh/mycode/aoc/2015/Day6/input.txt");
  char ch;
  string s[300];
  int x = 0; 
  while(in.get(ch)){
    if(ch != '\n'){
      s[x] += ch;
    }
    else{
      x++;
    }
  }

  int arr_1[300][5];
  
  readInstruction(s,arr_1);

  for (int i = 0; i < 300; i++)
  {
    cout<<arr_1[i][0]<<" "<<arr_1[i][1]<<" "<<arr_1[i][2]<<" "<<arr_1[i][3]<<" "<<arr_1[i][4]<<endl;
  }
  
  executeInstruction(arr_1,G);

  cout<<"No.of Lights swtiched on :"<<checkLights(G)<<endl;

  system("echo 'Problem Solved ' | lolcat ");
  return 0;
}

void readInstruction(string s[], int (&arr)[300][5]){
  //Getting the values for on ,off ,toggle
  regex a("(turn on)(.*)");
  regex b("(turn off)(.*)");
  for(int i = 0; i < 300; i++){
    if(regex_match(s[i], a)){
      arr[i][0] = 1;
    }
    else if(regex_match(s[i], b)){
      arr[i][0] = -1;
    }
    else{
      arr[i][0] = 0;
    }  
  }
  //Getting the values for x1,y1,x2,y2
  smatch m;
  regex aa("\\d{1,}");
  regex bb("\\d{1,}\\s");
  // regex cc("(?=through)\\s\\d{1,}(?=,)");
  // regex cc("\\b\\d+\\b\\s\\d+\\s(\\d+)");
  regex cc("\\s\\d+(?=,\\d+$)");
  regex dd("(\\d{1,}$)");
  for(int i = 0 ;i < 300; i++){
    int p;
    regex_search(s[i], m, aa);
    p = stoi(m.str());
    arr[i][1] = p; 
    regex_search(s[i], m, bb);
    p = stoi(m.str());
    arr[i][2] = p; 
    regex_search(s[i], m, cc);
    // size_t pos;
    p = stoi(m.str());
    arr[i][3] = p; 
    regex_search(s[i], m, dd);
    p = stoi(m.str());
    arr[i][4] = p; 
  }
}

void executeInstruction(int (&arr)[300][5], int (&G)[1000][1000]){
  for(int i = 0 ; i < 300; i++){
    if(arr[i][0] == 1){
      int x1 = arr[i][1];
      int y1 = arr[i][2];
      int x2 = arr[i][3];
      int y2 = arr[i][4];
      for(int j = x1; j <= x2; j++){
        for(int k = y1; k <= y2; k++){
          G[j][k] = 1;
        }
      }      
    }
    else if(arr[i][0] == -1){
      int x1 = arr[i][1];
      int y1 = arr[i][2];
      int x2 = arr[i][3];
      int y2 = arr[i][4];
      for(int j = x1; j <= x2; j++){
        for(int k = y1; k <= y2; k++){
          G[j][k] = -1;
        }
      }      
    }
    if(arr[i][0] == 0){
      int x1 = arr[i][1];
      int y1 = arr[i][2];
      int x2 = arr[i][3];
      int y2 = arr[i][4];
      for(int j = x1; j  <=x2; j++){
        for(int k = y1; k <=y2; k++){
          if(G[j][k] == 1){
            G[j][k] = -1;
          }
          else if(G[j][k] == -1){
            G[j][k] = 1;
          }
        }
      }      
    }
  }  
}


int checkLights(int (&G)[1000][1000]){
  int count = 0;
  for(int i = 0; i < 1000; i++){
    for(int j = 0; j < 1000; j++){
      if(G[i][j] == 1){
        count++;
      }
    }
  }
  return count;
}

void init(int (&G)[1000][1000]){
  for(int i = 0; i < 1000; i++){
    for(int j = 0; j < 1000; j++){
      G[i][j] = -1;
    }
  }
}