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

    ListNode *get_prev(ListNode *head, ListNode *wanted) {
        ListNode *it = head;
        while (it->next) {
            if (it->next == wanted)
                return it;
            it = it->next;
        }

        return nullptr;
    }

    ListNode *delete_node(ListNode *head, ListNode *get_previous) {
        ListNode *prev = get_prev(head, get_previous);
        ListNode *curr = prev->next;
        if (curr->next == nullptr) {
            prev->next = nullptr;
        } else {
            prev->next = curr->next;
        }
        delete curr;
        return prev;
    }

    ListNode *remove_duplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        std::unordered_set<int> set;
        int idx = 0;
        ListNode *temp = head;
        while (temp) {
            if (set.count(temp->val) == 1) {
                temp = delete_node(head, temp);
            } else if (set.count(temp->val) == 0) {
                set.insert(temp->val);
            }

            temp = temp->next;
            idx++;
        }
        return head;
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

    list.remove_duplicates(head);
    list.print(head);  // Output: 1 2 3
}