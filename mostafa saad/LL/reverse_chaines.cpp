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

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1)
        return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* GP = dummy;
    ListNode* GE = head;
    while (true) {
        int count = 0;
        while (GE && count < k) {
            GE = GE->next;
            count++;
        }

        if (count < k)
            break;

        ListNode* prev = GE;
        ListNode* curr = GP->next;
        ListNode* nex = nullptr;
        for (int i = 0; i < k; i++) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        ListNode* temp = GP->next;
        GP->next = prev;
        GP = temp;
    }
    return dummy->next;
}

int main() {
    ListNode* head1 = nullptr;
    append(head1, 1);
    append(head1, 2);
    append(head1, 3);
    append(head1, 4);
    append(head1, 5);
    append(head1, 6);
    append(head1, 7);
    // printList(head1);
    printList(reverseKGroup(head1, 3));
}