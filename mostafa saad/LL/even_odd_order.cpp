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

ListNode* deleteNode(ListNode* head, ListNode* curr, queue<int>& saved) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* target = curr->next;
    curr->next = target->next;
    saved.push(target->val);
    delete target;
    return curr->next;
}

ListNode* oddEvenList(ListNode* head) {
    queue<int> save;
    ListNode* temp = head;
    if (!temp || !temp->next || !temp->next->next)
        return temp;
    while (temp->next) {
        temp = deleteNode(head, temp, save);
    }
    while (!save.empty()) {
        append(head, save.front());
        save.pop();
    }
    printList(head);
    return head;
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
    append(head, 8);

    printList(head);  // Output: 1 2 3
    oddEvenList(head);
    return 0;
}
