#include <iostream>
#include <stack>
#include <string>
#include <cassert>

using namespace std;

string reverseString(const string &str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }

    string reversed = "";

    for (int i = 0; i < str.length(); i++)
    {
        char c = st.top();
        reversed.append(string(1, c));
        st.pop();
    }

    return reversed;
}

int main()
{
    assert(reverseString("hello") == "olleh");
}