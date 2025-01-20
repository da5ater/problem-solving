#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *rec(ListNode *&head, ListNode *curr)
{
    if (curr->next == nullptr)
    {
        head = curr;
        return curr;
    }

    ListNode *temp = rec(head, curr->next);
    temp->next = curr;
    curr->next = nullptr;
    return curr;
}

ListNode *reverseList(ListNode *head)
{

    ListNode *temp = head;
    rec(head, temp);
    return head;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *newHead = reverseList(head);
    while (newHead != nullptr)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    return 0;
}