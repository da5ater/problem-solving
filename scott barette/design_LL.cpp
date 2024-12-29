#include <iostream>

using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class MyLinkedList
{
    int length;
    Node *head;
    Node *tail;

public:
    MyLinkedList()
    {
        length = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int index)
    {
        if (index < 0 || index >= length)
            return -1;

        Node *temp = nullptr;

        if (index > length / 2)
        {
            temp = tail;
            for (int i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
        }
        else
        {
            temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }

        return temp->val;
    }

    void addAtHead(int val)
    {
        Node *NewNode = new Node(val);
        if (length == 0)
        {
            head = NewNode;
            tail = NewNode;
        }
        else
        {
            NewNode->next = head;
            head->prev = NewNode;
            head = NewNode;
        }
        length++;
    }

    void addAtTail(int val)
    {
        Node *NewNode = new Node(val);
        if (length == 0)
        {
            head = NewNode;
            tail = NewNode;
        }
        else
        {
            NewNode->prev = tail;
            tail->next = NewNode;
            tail = NewNode;
        }
        length++;
    }
    void addAtIndex(int index, int val)
    {
        Node *temp = nullptr;
        if (index < 0 || index > length)
            return void();
        if (length == index)
        {
            addAtTail(val);
            return;
        }
        else if (index == 0)
        {
            addAtHead(val);
            return;
        }
        else if (index > length / 2)
        {
            temp = tail;
            for (int i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
        }
        else
        {
            temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        Node *NewNode = new Node(val);
        NewNode->next = temp;
        NewNode->prev = temp->prev;
        temp->prev->next = NewNode;
        temp->prev = NewNode;
        length++;
        return void();
    }

    void deleteAtIndex(int index)
    {
        Node *temp = nullptr;
        if (index <= 0 || index >= length 
            return void();
        if (index == 0)
        {
            temp = head;
            head = head->next;
            if (head)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = prev;
            }
            delete temp;
            length--;
            return void();
        }
        else if (index == length - 1)
        {
            temp = tail;
            tail = tail->prev;
            if (tail)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            delete temp;
            length--;
            return void();
        }
        else if (index > length / 2)
        {
            temp = tail;
            for (int i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
        }
        else
        {
            temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        return void();
    }
};
/**
 *Your MyLinkedList object will be instantiated and called as such:
 *MyLinkedList* obj = new MyLinkedList();
 *int param_1 = obj->get(index);
 *obj->addAtHead(val);
 *obj->addAtTail(val);
 *obj->addAtIndex(index,val);
 *obj->deleteAtIndex(index);
 */

int main()
{
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(7);
    myLinkedList.addAtTail(2);
    myLinkedList.addAtTail(1);
    myLinkedList.addAtIndex(3, 0); // linked list becomes 1->2->3
    myLinkedList.deleteAtIndex(2); // now the linked list is 1->3
    cout << myLinkedList.get(1);   // return 2
    myLinkedList.deleteAtIndex(1); // now the linked list is 1->3
    cout << myLinkedList.get(1);   // return 3
}
