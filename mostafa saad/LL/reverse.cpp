#include <iostream>

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

// Function to insert a node at the beginning of the list
void insertAtBeginning(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

// Function to print the list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

ListNode* reverseList(ListNode* head) {
    for (ListNode* temp = head; temp; temp = temp->next) {
        if (temp->next) {
            std::swap(temp->val, temp->next->val);
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    ListNode* head = nullptr;  // Initialize head to nullptr

    insertAtBeginning(head, 5);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    printList(reverseList(head));  // Output: 1 2 3

    return 0;
}
