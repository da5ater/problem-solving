#include <map>
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

class MinStack
{
public:
    Node *head;
    Node *tail;
    int min;
    int size;
    map<int, int> map;
    MinStack()
    {
        min = 0;
        size = 0;
    }

    void push(int val)
    {
        Node *NewNode = new Node(val);

        if (size == 0)
        {
            head = NewNode;
            tail = NewNode;
        }
        else
        {
            NewNode->next = head;
            head = NewNode;
        }

        size++;

        if (val < min)
            min = val;

        map[-val]++;
    }

    void pop()
    {
        int val = head->val;
        if (size == 0 || size == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {

            Node *temp = head;

            head = head->next;

            if (map[-val] > 0)
            {
                map[-val]--;
            }
            else
            {
                map.erase(-val);
            }

            delete temp;
        }

        size--;
    }

    int top()
    {
        return head->val;
    }

    int getMin()
    {
        auto it = map.begin();
        return -it->first;
    }
};
int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();            // return 0
    cout << minStack.getMin(); // return -2
}