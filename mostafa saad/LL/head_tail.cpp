#include <iostream>

using namespace std;

struct Node

{
    int value;

    Node* next;

    Node(int value) : value{value}, next{nullptr} {};
    ~Node() {
        cout << "Destroy value " << value << "at " << this << endl;
    }
};

class LL

{
public:
    Node* head;

    Node* tail;

    int length;

public:
    LL(int value) {
        Node* NewNode = new Node(value);

        head = NewNode;

        tail = NewNode;
        length = 1;
    }

    void print() {
        Node* temp = head;

        while (temp) {
            cout << temp->value << " ";

            temp = temp->next;
        }

        cout << endl;
    }

    void insert(int value) {
        Node* NewNode = new Node(value);

        if (!head)

        {
            head = tail = NewNode;

        } else {
            tail->next = NewNode;

            tail = tail->next;
            length++;
        }
    }

    Node* get(size_t idx) {
        Node* temp = head;
        for (size_t i = 0; i < idx; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void swap_head_tail() {
        Node* start = get(1);
        Node* end = get(length - 2);

        tail->next = start;
        end->next = head;
        head->next = nullptr;

        Node* temp = head;
        head = tail;
        tail = temp;
    }
};

int main() {
    LL MyLL{1};
    MyLL.insert(2);
    MyLL.insert(3);
    MyLL.insert(4);
    MyLL.insert(5);

    cout << "head :" << MyLL.head->value << "tail : " << MyLL.tail->value
         << endl;
    MyLL.swap_head_tail();
    cout << "head :" << MyLL.head->value << "tail : " << MyLL.tail->value
         << endl;
}