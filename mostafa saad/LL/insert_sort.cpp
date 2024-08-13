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

    void merge_four(ListNode *&curr1, ListNode *&curr2, ListNode *&next1,
                    ListNode *&next2) {
        if (curr1->val <= curr2->val) {
            curr1->next = curr2;
            if (next1->val < next2->val)
                curr2->next = next1;
            if (next1->val > next2->val)
                curr2->next = next2;
        } else if (curr1->val > curr2->val)
            curr1->next = curr2;
        if (next1->val < next2->val)
            curr1->next = next1;
        if (next1->val > next2->val)
            curr1->next = next2;
    }

    ListNode *mergeTwoLists(ListNode *head1, ListNode *head2) {
        if (!head1 && !head2)
            return nullptr;
        if (!head1)
            return head2;
        if (!head2)
            return head1;

        ListNode *curr1 = head1;
        ListNode *next1 = head1->next;
        ListNode *curr2 = head2;
        ListNode *next2 = head2->next;

        while (next1 || next2) {
            merge_four(curr1, curr2, head1, head2);

            curr1 = next1;
            next1 = next1->next;
            curr2 = next2;
            next2 = next2->next;
        }
        return head1->val < head2->val ? head1 : head2;
    }
};

int main() {
    ListNode *head1 = nullptr;
    LinkedList list;
    ListNode *v1 = list.append(&head1, 1);
    ListNode *v2 = list.append(&head1, 3);

    ListNode *head2 = nullptr;
    LinkedList list2;
    ListNode *v11 = list.append(&head2, 2);
    ListNode *v22 = list.append(&head2, 4);
    list.print(head1);  // Output: 1 2 3
    list.print(head2);

    list.print(list.mergeTwoLists(head1, head2));
}