#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode* next) : val(x), next(next) {
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void append(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int getDecimalValue(ListNode* head) {
    if (!head)
        return;

    string out;

    ListNode* temp = head;

    while (temp) {
        out.append(to_string(temp->val));
        temp = temp->next;
    }

    int decimal = stoi(out, nullptr, 2);
    return decimal;
}

int main() {
    ListNode* head1 = nullptr;
    append(head1, 0);

    getDecimalValue(head1);
}