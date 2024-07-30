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

// Function to create a linked list
ListNode* createLinkedList(int values[], int size) {
    if (size == 0) {
        return nullptr;  // Empty list
    }

    // Create the head node
    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;

    // Create the rest of the nodes
    for (int i = 1; i < size; ++i) {
        ListNode* newNode = new ListNode(values[i]);
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

//--------------------------------------------------------------
ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    for (ListNode *temp = head->next, *prev = head; temp;
         prev = temp->next, temp = prev->next) {
        if (temp->next) {
            std::swap(prev->val, temp->val);
        }
    }
    return head;
}

//--------------------------------------------------------------

int main() {
    int values[] = {1, 2, 3, 4};
    int size = sizeof(values) / sizeof(values[0]);

    ListNode* head = createLinkedList(values, size);
    swapPairs(head);

    printList(head);

    // Remember to deallocate memory (not shown here for simplicity)

    return 0;
}
