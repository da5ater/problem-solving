#include <iostream>

using namespace std;

struct Node

{

    int value;

    Node *next;

    Node(int value) : value{value}, next{nullptr} {};
    ~Node()
    {

        cout << "Destroy value " << value << "at " << this << endl;
    }
};

class LL

{

private:
    Node *head;

    Node *tail;

    int length;

public:
    LL(int value)
    {

        Node *NewNode = new Node(value);

        head = NewNode;

        tail = NewNode;
        length = 1;
    }

    void print()
    {
        Node *temp = head;

        if (temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert(int value)
    {

        Node *NewNode = new Node(value);

        if (!head)

        {

            head = tail = NewNode;
        }
        else
        {
            tail->next = NewNode;

            tail = tail->next;
            length++;
        }
    }
};

int main()
{
    LL *MyLL = new LL(1);

    MyLL->insert(2);
    MyLL->insert(3);
    MyLL->insert(4);

    MyLL->print();
}