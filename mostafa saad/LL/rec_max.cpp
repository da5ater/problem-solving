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

    int maxx = INT_MIN;
    int max_recusive(Node* head) {
        if (head == nullptr) {
            return maxx;
        } else {
            if (head->value > maxx)
                maxx = head->value;
            max_recusive(head->next);
        }
        return maxx;
    }
}

;
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

    std::cout << MYLL.max_recusive(MYLL.head);
}