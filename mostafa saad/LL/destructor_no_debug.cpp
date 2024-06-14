#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value) : value{value}, next{nullptr} {

                                    };

    ~Node()
    {
        cout << "Destroy value ->" << value << " at " << this << endl;
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

    ~LL()
    {
        cout << "destructor is called\n";

        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            length--;
            temp = head;
        }
    }

    void print()
    {

        Node *temp = head;

        while (temp)
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
        }
        length++;
    }
};

int main()
{

    LL *MyLL = new LL(3);

    MyLL->insert(6);
    MyLL->insert(9);

    delete MyLL;
}