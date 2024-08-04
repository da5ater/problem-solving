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

    void insert_sorted(int value) {
        Node* new_node = new Node(value);
        if (length == 0) {
            head = new_node;
        } else if (length == 1) {
            head->value >= new_node->value ? new_node->next = head
                                           : head->next = new_node;
            tail->next = new_node;
            tail = tail->next;
            length++;
        } else {
            tail->next = new_node;
            tail = tail->next;
            length++;
            for (int i = length - 1; i > 0; i--) {
                Node* temp = head;
                for (int j = 0; j < i && temp; j++) {
                    if (temp->value > temp->next->value)

                        std::swap(temp->value, temp->next->value);
                    temp = temp->next;
                }
            }
        }
    }
};

int main() {
    LL MyLL{1};
    MyLL.insert_sorted(2);
    MyLL.insert_sorted(55);
    MyLL.insert_sorted(11);
    MyLL.insert_sorted(3);
    MyLL.insert_sorted(6);

    MyLL.print();
}