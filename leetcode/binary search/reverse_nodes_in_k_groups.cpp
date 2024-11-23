#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "empty" << endl;
            return;
        }
        while (temp->next != nullptr)
        {
            cout << temp->value << " <-> ";
            temp = temp->next;
        }
        cout << temp->value << endl;
    }

    Node *getHead()
    {
        return head;
    }

    Node *getTail()
    {
        return tail;
    }

    int getLength()
    {
        return length;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - The swapPairs function swaps adjacent pairs       |
    //   |   of nodes in a doubly linked list.                 |
    //   | - Return type: void                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Utilizes a dummyNode to simplify edge cases.      |
    //   | - Uses pointers to navigate and swap nodes.         |
    //   | - Pay close attention to the 'next' and 'prev'      |
    //   |   pointers of the nodes.                            |
    //   | - Works in-place; doesn't create new nodes.         |
    //   | - Always checks if the list is empty or has only    |
    //   |   one node.                                         |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    void swapPairs()
    {
        if (head == nullptr || length == 1)
            return void();

        Node *dummy = new Node(0);
        dummy->next = head;
        Node *GP = dummy;
        Node *GE = dummy->next;

        while (true)
        {
            int count = 0;
            while (GE && count < 2)
            {
                GE = GE->next;
                count++;
            }
            if (count < 2)
                break;

            Node *C = GP->next;
            Node *P = GE;
            Node *after = C->next;
            for (int i = 0; i < 2; i++)
            {
                // printList();
                after = C->next;
                C->next = P;
                C->prev = after;
                P = C;
                C = after;
            }

            Node *temp = GP->next;
            GP->next = P;
            GP = temp;
            GE = GP->next;
        }
        head = dummy->next;
    }
};

void t_main()
{
    DoublyLinkedList *d = new DoublyLinkedList(1);
    d->append(2);
    d->append(3);
    d->append(4);
    d->append(5);
    d->append(6);

    d->swapPairs();
    d->printList();
}

int main()
{
    DoublyLinkedList *d = new DoublyLinkedList(1);
    d->append(2);
    d->append(3);
    d->append(4);
    d->append(5);
    d->append(6);

    d->swapPairs();
    d->printList();

    string myGraphJson = "{\"kind\":{\"graph\":true},"
                         "\"nodes\":[{\"id\":\"1\"},{\"id\":\"2\"}],"
                         "\"edges\":[{\"from\":\"1\",\"to\":\"2\"}]}";
    cout << myGraphJson;
}
