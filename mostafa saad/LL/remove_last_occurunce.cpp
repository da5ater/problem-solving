#include <iostream>
#include <unordered_set>

using namespace std;
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
    ListNode *append(ListNode **head, int val) {
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
        return newNode;
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
        for (size_t i = 0; i < idx; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void delete_node(ListNode *head, int idx) {
        ListNode *prev = get(head, idx - 1);
        ListNode *curr = prev->next;
        prev->next = curr->next;
        delete curr;
    }

    void remove_last(ListNode *head, int key) {
        int idx = 0;
        int count = 0;
        ListNode *temp = head;
        while (temp) {
            if (temp->val == key)
                idx = count;
            temp = temp->next;
            count++;
        }
        delete_node(head, idx);
    }
};

int main() {
    ListNode *head = nullptr;
    LinkedList list;
    ListNode *v1 = list.append(&head, 1);
    ListNode *v2 = list.append(&head, 2);
    ListNode *v3 = list.append(&head, 2);
    ListNode *v4 = list.append(&head, 3);
    ListNode *v5 = list.append(&head, 3);
    ListNode *v6 = list.append(&head, 3);
    ListNode *v7 = list.append(&head, 4);
    ListNode *v8 = list.append(&head, 4);
    list.print(head);  // Output: 1 2 3
    list.remove_last(head, 3);
    list.print(head);
}