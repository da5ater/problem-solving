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

ListNode* get_prev(ListNode*& temp, ListNode* head) {
    ListNode* target = head;

    for (int i = 0; target->next != temp; i++)

    {
        target = target->next;
    }

    return target;
}

void rmv(ListNode*& temp, ListNode*& head) {
    if (temp == head) {
        ListNode* kill = temp;
        temp = temp->next;
        head = temp;
        delete kill;
    } else if (temp->next == nullptr) {  // check
        ListNode* previous = get_prev(temp, head);
        ListNode* kill = temp;
        temp = previous;
        temp->next = nullptr;
        delete kill;
    } else {
        ListNode* prev = get_prev(temp, head);
        ListNode* kill = temp;
        prev->next = temp->next;
        temp = temp->next;
        delete kill;
    }
}

void delete_occurunce(ListNode*& temp, ListNode*& head, int value) {
    while (temp && temp->val == value) {
        rmv(temp, head);
    }
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* temp = head;
    int value;
    if (!temp || !temp->next)
        return temp;

    while (temp) {
        value = temp->val;
        if (!temp->next) {
            return head;
        } else if (temp->next->val != value) {
            temp = temp->next;
        } else {
            delete_occurunce(temp, head, value);
        }
    }
    return head;
}

int main() {
    ListNode* head1 = nullptr;
    append(head1, 1);
    append(head1, 2);
    append(head1, 2);
    printList(head1);

    printList(deleteDuplicates(head1));
}