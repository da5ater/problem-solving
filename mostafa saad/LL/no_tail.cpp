#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) : value{value} {
        cout << "node creation ->" << value << endl;
        next = nullptr;
    }
};

class LL {
public:
    Node* head;

    LL(int value) {
        Node* NewNode = new Node(value);
        head = NewNode;
        NewNode->next = nullptr;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void add_element(int value) {
        Node* New_elm = new Node(value);
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = New_elm;
    }

    Node* get_tail() {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        return temp;
    }
};

int main() {
    LL* My_LL = new LL(1);

    My_LL->add_element(2);
    My_LL->add_element(3);
    My_LL->add_element(4);
    My_LL->add_element(5);

    My_LL->print();

    cout << My_LL->get_tail()->value;
}