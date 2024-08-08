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
private:
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

    void move_back(int key) {
        for (Node *curr = head, *prev = nullptr; curr->next;
             prev = curr, curr = curr->next) {
            if (curr->value == key) {
                if (!prev) {
                    Node* temp = curr;
                    curr = curr->next;
                    tail->next = temp;
                    temp->next = nullptr;
                    tail = temp;
                    head = curr;

                } else {
                    prev->next = curr->next;
                    tail->next = curr;
                    curr = curr->next;
                    tail->next->next = nullptr;
                    tail = tail->next;
                }
            }
        }
    }
};

int main() {
    LL MYLL{2};
    MYLL.insert(10);
    MYLL.insert(2);
    MYLL.insert(3);
    MYLL.insert(2);
    MYLL.insert(4);
    MYLL.insert(2);
    MYLL.insert(2);
    MYLL.print();
    MYLL.move_back(2);
    MYLL.print();
}