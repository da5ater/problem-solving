// the problem is "implement a code to reverse a set of characters using stack concept"

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string s1 = "ABC";

    stack<char> stack;

    for (int i = 0; i < s1.length(); i++)
    {
        stack.push(s1[i]);
    }

    string s2;

    while (!stack.empty())
    {
        s2 += stack.top();
        stack.pop();
    }

    cout << s2;
}