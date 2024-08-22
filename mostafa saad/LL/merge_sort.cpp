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

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1 && !list2) {
            return nullptr;
        } else if (!list1) {
            return list2;
        } else {
            return list1;
        }

        ListNode *temp = nullptr;
        ListNode *head = nullptr;

        if (list1->val <= list2->val) {
            temp = list1;
            head = list1;
            list1 = list1->next;
        } else {
            temp = list2;
            head = list2;
            list2 = list2->next;
        }
        while (list1 || list2) {
            if (!list1) {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            } else if (!list2) {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            } else if (list1->val < list2->val) {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode *head1 = nullptr;
    LinkedList list;
    ListNode *v1 = list.append(&head1, 1);
    ListNode *v2 = list.append(&head1, 2);
    ListNode *v3 = list.append(&head1, 4);

    ListNode *head2 = nullptr;
    LinkedList list2;
    ListNode *v11 = list.append(&head2, 1);
    ListNode *v22 = list.append(&head2, 3);
    ListNode *v33 = list.append(&head2, 4);

    list.print(head1);  // Output: 1 2 3
    list.print(head2);
    list.print(list.mergeTwoLists(head1, head2));
}