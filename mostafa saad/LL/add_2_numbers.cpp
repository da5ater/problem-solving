#include <iostream>
#include <queue>

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

int main() {
    ListNode* head1 = nullptr;
    append(head1, 2);
    append(head1, 3);
    append(head1, 4);

    ListNode* head2 = nullptr;
    append(head2, 5);
    append(head2, 6);
    append(head2, 4);

    printList(head1);
    printList(head2);

    cout << 10 % 20;

    return 0;
}