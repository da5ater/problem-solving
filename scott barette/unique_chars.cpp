#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{

    string line;

    getline(cin, line);

    unordered_set<char> set;

    for (char c : line)
    {

        if (set.find(c) == set.end())
        {
            set.insert(c);
        }
        else
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes";
}
