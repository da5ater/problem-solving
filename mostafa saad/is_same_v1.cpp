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

    bool is_same(LL*& MyLL) {
        if (this->length != MyLL->length) {
            return false;
        }
        Node* temp1 = this->head;
        Node* temp2 = MyLL->head;
        while (temp1) {
            if (temp1->value != temp2->value) {
                return false;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};

int main() {
    LL* MyLL1 = new LL(1);

    MyLL1->insert(2);
    MyLL1->insert(3);
    MyLL1->insert(4);

    LL* MyLL2 = new LL(1);

    MyLL2->insert(2);
    MyLL2->insert(4);
    MyLL2->insert(4);

    cout << MyLL1->is_same(MyLL2) << endl;
}