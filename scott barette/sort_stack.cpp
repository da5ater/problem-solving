#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

bool operator==(const std::stack<int> &s1, const std::stack<int> &s2)
{
    std::stack<int> temp1 = s1;
    std::stack<int> temp2 = s2;
    while (!temp1.empty() && !temp2.empty())
    {
        if (temp1.top() != temp2.top())
        {
            return false;
        }
        temp1.pop();
        temp2.pop();
    }
    return temp1.empty() && temp2.empty();
}

void insert(int value, stack<int> &s)
{
    if (s.empty() || value > s.top())
    {
        s.push(value);
        return;
    }
    else
    {
        int elm = s.top();
        s.pop();
        insert(value, s);
        s.push(elm);
    }
}

void sort(stack<int> &st)
{
    if (st.empty() || st.size() == 1)
    {
        return;
    }
    else
    {
        int value = st.top();
        st.pop();
        sort(st);
        insert(value, st);
    }
}

void t_sort()
{
    stack<int> s;
    sort(s);
    assert(s.empty());

    stack<int> s0;
    s0.push(1);
    sort(s0);
    assert(s0 == s0);

    stack<int> s1;
    s1.push(3);
    s1.push(2);
    s1.push(1);
    stack<int> s2;
    s2.push(1);
    s2.push(2);
    s1.push(3);
    sort(s1);
    assert(s1 == s2);

    stack<int> s3;
    s1.push(3);
    s1.push(11);
    s1.push(50);
    stack<int> s4;
    s4.push(3);
    s4.push(11);
    s4.push(50);
    sort(s3);
    assert(s3 == s4);
}
int main()
{
    t_sort();
}