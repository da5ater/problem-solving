#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    int count = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < students.size(); i++)
    {
        map[students[i]]++;
    }

    while (students.size() != 0)
    {
        if (students[0] == sandwiches[0])
        {
            map[students[0]]--;
            students.erase(students.begin());
            sandwiches.erase(sandwiches.begin());
        }
        else
        {
            if (map[sandwiches[0]] == 0)
                return students.size();

            students.push_back(students[0]);
            students.erase(students.begin());
        }
    }
    return 0;
}

void T_main()
{
    vector<int> st1{1, 1, 0, 0};
    vector<int> sd1{0, 1, 0, 1};
    assert(countStudents(st1, sd1) == 0);

    vector<int> st2{1, 1, 1, 0, 0, 1};
    vector<int> sd2{1, 0, 0, 0, 1, 1};
    assert(countStudents(st2, sd2) == 3);

    vector<int> st3{1, 1, 1};
    vector<int> sd3{1, 0, 0};
    assert(countStudents(st3, sd3) == 2);

    vector<int> sd4{1, 1, 1};
    vector<int> st4{1, 0, 0};
    assert(countStudents(st3, sd3) == 2);

    vector<int> st5{1, 1, 1};
    vector<int> sd5{0, 0, 0};
    assert(countStudents(st5, sd5) == 3);
    assert(countStudents(st3, sd3) == 2);

    vector<int> st6{1, 0, 1};
    vector<int> sd6{0, 1, 0};
    assert(countStudents(st5, sd5) == 3);
}

int main()
{
    T_main();
}