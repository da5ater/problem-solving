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

ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;  // If the list is empty or has only one node, return as is

    ListNode* odd = head;  // Initialize odd pointer to the head of the list
    ListNode* even = head->next;  // Initialize even pointer to the second node
    ListNode* temp = even;        // Store the start of the even list

    while (even != nullptr && even->next != nullptr) {
        // Update odd and even pointers to skip one node each
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    // Connect the end of the odd list to the start of the even list
    odd->next = temp;

    return head;  // Return the modified list
}

int main() {
    ListNode* head = nullptr;

    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    append(head, 6);
    append(head, 7);

    printList(head);  // Output: 1 2 3
    oddEvenList(head);
    return 0;
}
