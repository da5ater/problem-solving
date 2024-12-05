#include <iostream>
#include <map>
#include <cassert>
using namespace std;

int firstUniqChar(string s)
{
    map<char, int> map;

    for (auto &c : s)
    {
        map[c]++;
    }

    int min = -1;

    for (auto p : map)
    {
        if (p.second == 1)
        {
            (min < s.find(p.first)) ? min : min = s.find(p.first);
        }
    };
    return min;
};
void t_main()
{
    assert(firstUniqChar("loveleetcode") == 2);
};

int main()
{
    t_main();
}