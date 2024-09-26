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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head->next)
        return head;

    ListNode* group_prev = nullptr;
    ListNode* curr = nullptr;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    if (left == 1) {
        group_prev = head;
        curr = head;
        for (int i = 0; i < right - left + 1; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        group_prev->next = curr;
        return prev;
    }

    group_prev = head;
    for (int i = 1; i < left - 1; i++) {
        group_prev = group_prev->next;
    }

    curr = group_prev->next;
    ListNode* group_head = group_prev->next;

    next = curr->next;

    for (int i = 0; i < right - left + 1; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    group_prev->next = prev;
    group_head->next = curr;

    return head;
}

int main() {
    ListNode* head1 = nullptr;
    append(head1, 5);
    append(head1, 3);

    printList(reverseBetween(head1, 1, 2));
}