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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = nullptr;
    int sum = 0;
    int rem = 0;

    while (l2 || l1) {
        if (!l2) {
            sum = l1->val + rem;
        } else if (!l1) {
            sum = l2->val + rem;
        } else {
            sum = l2->val + l1->val + rem;
        }
        if (sum >= 10) {
            sum = sum % 10;
            rem = 1;
        } else {
            rem = 0;
        }
        append(result, sum);
        if (!l1 && l2->next == nullptr && rem != 0 ||
            !l2 && l1->next == nullptr && rem != 0 ||
            l2 && !l2->next && l1 && !l1->next && rem != 0)
            append(result, rem);

        if (l2) {
            l2 = l2->next;
        }
        (l1) ? l1 = l1->next : l1;
    }
    return result;
}

int main() {
    ListNode* head1 = nullptr;
    append(head1, 9);
    append(head1, 9);
    append(head1, 9);
    append(head1, 9);
    append(head1, 9);
    append(head1, 9);
    append(head1, 9);

    ListNode* head2 = nullptr;
    append(head2, 9);
    append(head2, 9);
    append(head2, 9);
    append(head2, 9);

    printList(head1);
    printList(head2);

    printList(addTwoNumbers(head1, head2));

    return 0;
}