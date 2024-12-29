#include <iostream>
using namespace std;

class Node
{
public:
    string url;
    Node *next;
    Node *prev;

    Node(string value)
    {
        url = value;
        next = nullptr;
        prev = nullptr;
    }
};

class BrowserHistory
{
    Node *head;
    Node *tail;
    int length;
    Node *marker;

public:
    BrowserHistory(string homepage)
    {
        Node *NewNode = new Node(homepage);
        head = NewNode;
        tail = NewNode;
        length = 1;
        marker = head;
    }

    void visit(string url)
    {
        Node *NewNode = new Node(url);
        if (marker->next)
        {

            Node *temp = marker->next;
            temp->prev = nullptr;

            tail = marker;
            delete temp;
        }
        marker->next = NewNode;
        NewNode->prev = marker;
        NewNode->prev = marker;
        marker = marker->next;
        tail = marker;
        length++;
    };

    string back(int steps)
    {
        if (marker == head)
        {
            return head->url;
        }
        else
        {
            while (marker->prev && steps > 0)
            {
                marker = marker->prev;
                steps--;
            }

            return marker->url;
        }
    }

    string
    forward(int steps)
    {
        if (marker == tail)
        {
            return marker->url;
        }
        else if (steps > length)
        {
            marker = tail;
            return marker->url;
        }
        else
        {
            while (marker->next && steps > 0)
            {
                marker = marker->next;
                steps--;
            }

            return marker->url;
        }
    }

    // private:
    //     bool in_DLL(string url){

    //     }
};

int main()
{

    BrowserHistory *obj = new BrowserHistory("zav.com");
    obj->visit("kni.com");
    cout << obj->back(7) << endl;    // zav
    cout << obj->back(7) << endl;    // zav
    cout << obj->forward(5) << endl; // kni
    cout << obj->forward(1) << endl; // kni
    obj->visit("pwrrbnw.com");
    obj->visit("mosohif.com");
    cout << obj->back(9) << endl; // zav
}