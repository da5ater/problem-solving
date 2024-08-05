#include <iostream>

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

    int calculate_length(ListNode *head) {
        int count = 0;
        ListNode *temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode *get_K(ListNode *head, int k) {
        int i = 0;
        int length = calculate_length(head);
        for (ListNode *temp = head; temp; temp = temp->next, i++) {
            if (i >= length - k) {
                return temp;
            }
        }
        return nullptr;
    }

    ListNode *get_tail(ListNode *head) {
        ListNode *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        return temp;
    }

    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return nullptr;
        } else if (head->next == nullptr) {
            return head;
        }
        {}
        k = k % calculate_length(head);
        ListNode *temp = get_K(head, k);
        ListNode *new_tail = get_K(head, k + 1);
        ListNode *tail = get_tail(head);

        tail->next = head;
        head = temp;
        new_tail->next = nullptr;
        return head;
    }
};

int main() {
    ListNode *head = nullptr;
    LinkedList list;
    list.append(&head, 0);
    list.append(&head, 1);
    list.append(&head, 2);
    list.print(head);  // Output: 1 2 3
    std ::cout << 2 % 2;
    // list.print(list.rotateRight(head, 4));
    return 0;
}