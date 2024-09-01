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

void DeleteFirst(ListNode*& head) {
    ListNode* temp = head;

    if (!head->next) {
        head = nullptr;
        delete temp;
    } else {
        head = head->next;
        delete temp;
    }
}

void deleteLast(ListNode*& head, ListNode*& prev) {
    ListNode* kill = prev->next;
    prev->next = nullptr;
    delete kill;
}

void DeleteNode(ListNode*& head, ListNode*& prev) {
    if (head->next && !prev->next->next) {
        return deleteLast(head, prev);
    } else {
        ListNode* kill = prev->next;

        prev->next = prev->next->next;  // will be deleted

        delete kill;
    }
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) {
        return nullptr;
    } else if (!head->next) {
        DeleteFirst(head);
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    if (!fast) {
        DeleteFirst(head);
        return head;
    }

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    DeleteNode(head, slow);
    return head;
}

int main() {
    ListNode* head1 = nullptr;
    append(head1, 1);
    printList(removeNthFromEnd(head1, 1));
    // printList(removeNthFromEnd(head1, 1));
}