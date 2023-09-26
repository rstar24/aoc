#include <bits/stdc++.h>
using namespace std;
//For Solving the part 2 of the
//puzzle better to create a new file
//rather than editing the previous one

#define MAX_LENGTH 16000
#define MAX_WIDTH 16000
#define ORIGIN 8000

int main(){
    //open the input file
    string str1("/home/rishabh/mycode/aoc/2015/Day3/input.txt");
    ifstream myinput;
    myinput.open(str1);
    if (!myinput.is_open()){
        cerr<< "Some error in opening the file" <<endl;
    }

    char ch ;
    int sz = 0 ;
    while (myinput.get(ch)){
        sz++;
    }
    cout <<sz <<endl;
    myinput.clear();
    myinput.seekg(0,std::ios::beg);

    //Making the grid of houses ;
    //Initializing all the no of present to the houses as 
    // Zero at first 
    vector<vector<int>> grid(MAX_LENGTH,vector<int>(MAX_WIDTH,0));
    grid[ORIGIN][ORIGIN] = 1;
    int s_loc_x= ORIGIN;
    int s_loc_y= ORIGIN;
    int r_loc_x= ORIGIN;
    int r_loc_y= ORIGIN;

    for(int i = 0 ; i < sz; i++){
        myinput.get(ch);
        if ( (i % 2) == 1){
            if (ch == '^'){
                grid[s_loc_x][s_loc_y+1]++;
                s_loc_y++;
            }
            else if(ch == 'v'){
                grid[s_loc_x][s_loc_y-1]++;
                s_loc_y--;
            }
            else if(ch == '<'){
                grid[s_loc_x-1][s_loc_y]++;
                s_loc_x--;
            }
            else if(ch == '>'){
                grid[s_loc_x+1][s_loc_y]++;
                s_loc_x++;
            }
        }
        else if( (i % 2) == 0){
            if (ch == '^'){
                grid[r_loc_x][r_loc_y+1]++;
                r_loc_y++;
            }
            else if(ch == 'v'){
                grid[r_loc_x][r_loc_y-1]++;
                r_loc_y--;
            }
            else if(ch == '<'){
                grid[r_loc_x-1][r_loc_y]++;
                r_loc_x--;
            }
            else if(ch == '>'){
                grid[r_loc_x+1][r_loc_y]++;
                r_loc_x++;
            }
        }
    }
    int main_counter = 0;
    for( int i = 0 ; i < MAX_LENGTH ; i++){
        for (int j = 0 ; j < MAX_LENGTH ; j++){
            if (grid[i][j] >=1) {
                main_counter++;
            }
        }
    }

    cout<< "No of houses which recieved \nat least one gift :" 
        << main_counter <<endl;
    //Finaly solved 2 stars added 
    return 0;
}