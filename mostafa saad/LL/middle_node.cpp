#include <cmath>
#include <iostream>

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

ListNode* get(ListNode* head, int length) {
    ListNode* temp = head;

    for (int i = 0; i < length; i++) {
        temp = temp->next;
    }
    return temp;
}

ListNode* middleNode(ListNode* head) {
    if (!head->next) {
        return head;
    } else if (!head->next->next)
        return head->next;

    ListNode* temp = head;

    int length = 0;
    while (temp) {
        length++;
        temp = temp->next;
    }

    ListNode* mid = nullptr;
    if (length % 2 == 0) {
        mid = get(head, (length / 2));
    } else {
        mid = get(head, std::ceil(length / 2));
    }
    return mid;
}
int main() {
    ListNode* head1 = nullptr;
    append(head1, 1);
    append(head1, 2);
    append(head1, 3);
    append(head1, 4);

    printList(head1);

    std::cout << middleNode(head1)->val;
}