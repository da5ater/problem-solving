#include <iostream>

using namespace std;

struct Node

{
    int value;

    Node* next;

    Node(int value) : value{value}, next{nullptr} {
        cout << "create value " << value << "at " << this << endl;
    };
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

    Node* get_nth(int index) {
        Node* temp = head;

        for (int i = 0; i < index; i++)

        {
            temp = temp->next;
        }

        return temp;
    }

    void delete_first() {
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void delete_last() {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    void delete_nth(int index) {
        Node* curr = get_nth(index);
        Node* prev = get_nth(index - 1);
        prev = curr->next;
        delete curr;
    }
};

int main() {
}