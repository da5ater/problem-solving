#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class LinkedList {
public:
    void append(ListNode **head, int val) {
        ListNode *newNode = new ListNode(val);
        if (*head == nullptr) {
            *head = newNode;
        } else {
            ListNode *curr = *head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void print(ListNode *head) {
        ListNode *curr = head;
        while (curr) {
            std::cout << curr->val << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    ListNode *get(ListNode *head, int idx) {
        ListNode *temp = head;
        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void delete_node(ListNode *head, int idx) {
    }
};

int main() {
    ListNode *head = nullptr;
    LinkedList list;
    list.append(&head, 1);
    list.append(&head, 2);
    list.append(&head, 3);
    list.print(head);  // Output: 1 2 3

    std::cout << list.get(head, 2)->val;
}