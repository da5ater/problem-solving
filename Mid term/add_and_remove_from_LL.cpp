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
            length++;
        }
    }

    Node *get(int index)
    {
        Node *temp = head;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    void DeleteNode(int index)
    {
        Node *prev = get(index - 1);
        Node *temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }

    void InsertNode(int value, int index)
    {
        Node *NewNode = new Node(value);

        Node *prev = get(index - 1);

        NewNode->next = prev->next;

        prev->next = NewNode;

        length++;
    }
};

int main()
{
    LL *MyLL = new LL(1);

    MyLL->insert(2);
    MyLL->insert(3);
    MyLL->insert(4);

    MyLL->DeleteNode(2);

    MyLL->print();

    MyLL->InsertNode(3, 2);

    MyLL->print();
}