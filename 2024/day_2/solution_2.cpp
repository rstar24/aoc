#include <bits/stdc++.h>
using namespace std;

// solution for part one
bool isSafe(vector<int> arr);

// for part two
bool removeOne(vector<int> arr);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // read the input file
    ifstream f(".\\input.txt");

    if (!f.is_open())
    {
        cerr << "Error opening the file" << endl;
        return 1;
    }

    // store the list of the number in two vectors
    string line;
    int result = 0;

    while (getline(f, line))
    {

        istringstream stream(line);
        int num;
        vector<int> arr;
        while (stream >> num)
        {
            arr.push_back(num);
        }

        if (removeOne(arr))
        {
            result++;
        }
    }

    cout << " The part two solution is " << result << endl;

    vector<int> arr1 = {7,6,4,2,1};
    if (removeOne(arr1))
    {
        cout << "Safe" << endl;
    }
    else
    {
        cout << "Unsafe" << endl;
    }

    vector<int> arr2 = {1,2,7,8,9};
    if (removeOne(arr2))
    {
        cout << "Safe" << endl;
    }
    else
    {
        cout << "Unsafe" << endl;
    }

    vector<int> arr3 = {9, 7, 6, 2, 1};
    if (removeOne(arr3))
    {
        cout << "Safe" << endl;
    }
    else
    {
        cout << "Unsafe" << endl;
    }

    vector<int> arr4 = {1,3,2,4,5};
    if (removeOne(arr4))
    {
        cout << "Safe" << endl;
    }
    else
    {
        cout << "Unsafe" << endl;
    }

    vector<int> arr5 = {8,6,4,4,1};
    if (removeOne(arr5))
    {
        cout << "Safe" << endl;
    }
    else
    {
        cout << "Unsafe" << endl;
    }

    vector<int> arr6 = {1,3,6,7,9};
    if (removeOne(arr6))
    {
        cout << "Safe" << endl;
    }
    else
    {
        cout << "Unsafe" << endl;
    }


    return 0;
}

bool isSafe(vector<int> arr)
{
    // if not sorted than  return false

    if (arr[0] < arr[1])
    {
        if (is_sorted(arr.begin(), arr.end()))
        {
            // should not contain any duplicates
            set<int> set_ck;
            for (auto x : arr)
            {
                set_ck.insert(x);
            }

            if (set_ck.size() != arr.size())
            {
                return false;
            }

            for (int i = 1; i < arr.size(); i++)
            {
                if ((abs(arr[i - 1] - arr[i]) <= 3) &&
                    (abs(arr[i - 1] - arr[i]) >= 1))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }

            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (is_sorted(arr.begin(), arr.end(), greater<int>()))
        {
            // should not contain any duplicates
            set<int> set_ck;
            for (auto x : arr)
            {
                set_ck.insert(x);
            }

            if (set_ck.size() != arr.size())
            {
                return false;
            }

            for (int i = 1; i < arr.size(); i++)
            {
                if ((abs(arr[i - 1] - arr[i]) <= 3) &&
                    (abs(arr[i - 1] - arr[i]) >= 1))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }

            return true;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool removeOne(vector<int> arr){
    vector<vector<int>> combinations;
    int sz  = arr.size();
    for (int i = 0 ; i < sz ; i++){
        vector<int> temp;
        for( int j = 0 ; j < sz ; j++){
            if ( i == j ){
                continue;
            }
            else {
                temp.push_back(arr[j]);
            }
        }
        combinations.push_back(temp);
    }

    for (auto x : combinations){
        if (isSafe(x)){
            return true;
        }
    }

    return false;
}