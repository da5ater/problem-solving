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

    Node* get(int index) {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    int find(int value) {
        Node* temp = head;
        int idx = 0;
        while (temp) {
            if (temp->value == value)
                return idx;

            temp = temp->next;
            ++idx;
        }
        return -1;
    }

    void delete_node(int value) {
        int indx = find(value);
        Node* temp = get(indx);
        Node* prev = get(--indx);

        prev->next = temp->next;
        delete temp;
    }
};

int main() {
    LL* MyLL = new LL{1};
    MyLL->insert(2);
    MyLL->insert(3);
    MyLL->insert(4);
    MyLL->insert(5);

    MyLL->delete_node(2);

    MyLL->print();
}