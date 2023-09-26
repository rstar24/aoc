#include <bits/stdc++.h>

using namespace std;
// trying cpp to solve the puzzle
#define MAX_LENGTH 16000
#define MAX_WIDTH 16000
#define ORIGIN 8000

int main(){
    //Making a grid of 16000 x 1600
    vector<vector<int>> grid(MAX_LENGTH, vector<int>(MAX_WIDTH,0));
    grid[ORIGIN][ORIGIN] = 1;
    cout << "length of grid : " << grid.size() << "\n";
    cout << "width of grid : " << grid[0].size() << "\n";

    //For opening the file for reading the directions
    string str2("/home/rishabh/mycode/aoc/2015/Day3/input.txt");
    ifstream myinput;
    myinput.open(str2);
    
    if (!myinput.is_open()){
        cerr << "Error : Could not open the file"<< endl;
        return 1;
    }
    char ch;
    int sz=0;
    while(myinput.get(ch)){
        sz++;
    }
    cout << "The directions characters in the file : " <<sz <<endl;
    //Both the function should be called one after another
    //for the pointer being shifted to start
    myinput.clear();
    myinput.seekg(0, std::ios::beg);

    if (!myinput.is_open()){
        cerr << "Error : Could not open the file"<< endl;
        return 1;
    }
    int i = 1;
    int j = 1;
    int loc_x = ORIGIN;
    int loc_y = ORIGIN;

    for(int i = 0; i < sz ; i++){
        myinput.get(ch);
        if (ch == '^'){
            grid[loc_x][loc_y+1]++;
            loc_y++;
        }
        else if (ch == 'v'){
            grid[loc_x][loc_y-1]++;
            loc_y--;
        }
        else if(ch == '<'){
            grid[loc_x-1][loc_y]++;
            loc_x--;
        }
        else if (ch == '>'){
            grid[loc_x+1][loc_y]++;
            loc_x++;
        }
    }
    int main_counter=0;
    for (int i = 0 ;i < MAX_LENGTH ; i++){
        for (int j = 0 ; j < MAX_LENGTH; j++){
            if (grid[i][j] >= 1){
                main_counter++;
            }
        }
    }
    cout << "This nubmer of houses who " 
        <<  "recieved gifts atleast at once : "
        << main_counter
        << endl;

    return 0;
}