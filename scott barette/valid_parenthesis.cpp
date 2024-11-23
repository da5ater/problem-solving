#include <iostream>
#include <cassert>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s)
{
    char open1 = '(';
    char open2 = '{';
    char open3 = '[';
    char closed1 = ')';
    char closed2 = '}';
    char closed3 = ']';

    unordered_map<char, char> closed = {{closed1, open1},
                                        {closed2, open2},
                                        {closed3, open3}};

    stack<char> MyStack;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == open1 || s[i] == open2 || s[i] == open3)
        {
            MyStack.push(s[i]);
        }
        else
        {
            if (!MyStack.empty() || closed.at(s[i]) == MyStack.top())
            {
                MyStack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return (MyStack.empty()) ? true : false;
}

int main()
{
    assert(isValid("(]") == false);
}