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

void neo_append(ListNode*& head, ListNode*& tail) {
    ListNode* temp = head;
    head = head->next;
    tail->next = temp;
    tail = temp;
    tail->next = nullptr;
}

ListNode* partition(ListNode* head, int x) {
    if (!head) {
        return nullptr;
    }

    ListNode* Sdummy = new ListNode(0);
    ListNode* Stail = Sdummy;
    ListNode* Bdummy = new ListNode(0);
    ListNode* Btail = Bdummy;

    while (head) {
        if (head->val < x) {
            neo_append(head, Stail);
        } else {
            neo_append(head, Btail);
        }
    }
    Stail->next = Bdummy->next;
    return Sdummy->next;
}

int main() {
    ListNode* head1 = nullptr;
    append(head1, 1);

    printList(partition(head1, ));
}