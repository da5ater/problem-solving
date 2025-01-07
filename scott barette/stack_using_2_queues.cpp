#include <queue>
#include <iostream>
using namespace std;

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }

        while (!q2.empty())
        {

            int x = q2.front();
            q2.pop();
            q1.push(x);
        }
    };
    int pop()
    {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    cout << obj->pop() << endl;
    cout << obj->top() << endl;
    cout << obj->empty() << endl;
    return 0;
}