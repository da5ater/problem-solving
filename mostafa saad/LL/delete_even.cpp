#include <iostream>
using namespace std;

struct Node

{
    int value;

    Node* next;

    Node(int value) : value{value}, next{nullptr} {};
    ~Node() {
        cout << "Destroy value " << value << " at " << this << endl;
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

    Node* get(Node* wanted) {
        Node* temp = head;

        while (temp) {
            if (temp->next == wanted) {
                return temp;
            }
            temp = temp->next;
        }
        cout << "none";
        return nullptr;
    }

    void delete_even() {
        Node* temp = head;
        int i = 1;
        while (temp) {
            if (i % 2 == 0) {
                Node* prev = get(temp);
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
                i++;
            } else {
                temp = temp->next;
                i++;
            }
        }
    };
};

int main() {
    LL MYLL{1};
    MYLL.insert(2);
    MYLL.insert(3);
    MYLL.insert(4);
    MYLL.insert(5);
    MYLL.insert(6);

    MYLL.print();

    MYLL.delete_even();
    MYLL.print();
}