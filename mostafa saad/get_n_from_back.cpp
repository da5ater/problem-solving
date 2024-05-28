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
        }

        length++;
    }

    Node* find_in_the_back(int n) {
        Node* temp = head;
        for (int i = 0; i < length - n; i++) {
            temp = temp->next;
        }

        return temp;
    }
};

int main() {
    LL* MyLL = new LL(1);

    MyLL->insert(2);
    MyLL->insert(3);
    MyLL->insert(4);

    int value = MyLL->find_in_the_back(2)->value;

    cout << value << endl;
    return 0;
}