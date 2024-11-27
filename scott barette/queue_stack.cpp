#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class MyQueue
{
public:
    stack<int> in;
    stack<int> out;
    MyQueue()
    {
    }
    void push(int x)
    {
        while (!out.empty())
        {
            in.push(out.top());
            out.pop();
        }
        in.push(x);
        while (!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
    }

    int pop()
    {
        return out.top();
        out.pop();
    }

    int peek()
    {
        return out.top();
    }

    bool empty()
    {
        return out.empty();
    }
};

void t_main()
{
    MyQueue obj1;
    obj1.push(1);
    obj1.pop();
    assert(obj1.empty() == true);
}

int main()
{
    t_main();
}