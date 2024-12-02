#include <bits/stdc++.h>
using namespace std;

// solution for part one
bool isSafe(vector<int> arr);


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

        if (isSafe(arr))
        {
            result++;
        }
    }

    cout << " The part one solution is " << result << endl;

    vector<int> arr1 = {7,6,4,2,1};
    if (isSafe(arr1))
    {
        cout << "Safe" << endl;
    }
    else
    {
        cout << "Unsafe" << endl;
    }

    vector<int> arr2 = {1,2,7,8,9};
    if (isSafe(arr2))
    {
        cout << "Safe" << endl;
    }
    else
    {
        cout << "Unsafe" << endl;
    }

    vector<int> arr3 = {9, 7, 6, 2, 1};
    if (isSafe(arr3))
    {
        cout << "Safe" << endl;
    }
    else
    {
        cout << "Unsafe" << endl;
    }

    vector<int> arr4 = {1,3,2,4,5};
    if (isSafe(arr4))
    {
        cout << "Safe" << endl;
    }
    else
    {
        cout << "Unsafe" << endl;
    }

    vector<int> arr5 = {8,6,4,4,1};
    if (isSafe(arr5))
    {
        cout << "Safe" << endl;
    }
    else
    {
        cout << "Unsafe" << endl;
    }

    vector<int> arr6 = {1,3,6,7,9};
    if (isSafe(arr6))
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

