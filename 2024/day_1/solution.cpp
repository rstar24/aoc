#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // read the input file
    std::ifstream  f(".\\input.txt");

    if (!f.is_open()){
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    // store the list of the number in two vectors
    std::string line;
    vector<int> llist;
    vector<int> rlist;
    int result ;

    while ( std::getline(f,line)){
        std::istringstream stream(line);
        int x , y;
        stream >> x >> y;
        llist.push_back(x);
        rlist.push_back(y);
    }

    // total difference of the list with each element in ascending order 
    std::sort(llist.begin(),llist.end());
    std::sort(rlist.begin(),rlist.end());

    int sz = rlist.size();

    for (int i = 0 ; i < sz ; i++){
        result += abs(llist[i]-rlist[i]);
    }

    std::cout << "Size of the First List : "<< llist.size() << endl;
    std::cout << "Size of the Second List : "<< rlist.size() << endl;
    std::cout << "\nSolution of the first part the total difference in lists is : "<< result << endl;

    // Make a simple hash map for part two of the problem
    // unordered_map<int,int> map;
    multiset<int> ms ;
    result = 0;
    for (auto x : rlist){
        ms.insert(x);
    }


    for (int i = 0 ; i < sz; i++){
        
        if (ms.find(llist[i]) != ms.end()){
            // add the similarity score to result
            result += (llist[i] * ms.count(llist[i]));
            ms.erase(llist[i]);

        }
        else {
            continue;
        }
    }

    std::cout << "\nSolution of the Second part the total similarity score is : "<< result << endl;

    return 0 ;
}