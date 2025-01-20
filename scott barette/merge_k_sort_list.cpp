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

void merge(vector<ListNode *> &lists, ListNode *head1, ListNode *head2, int storage)
{
    if (head1 == nullptr)
    {
        lists[storage] = head2;
        return;
    }

    if (head2 == nullptr)
    {
        lists[storage] = head1;
        return;
    }

    ListNode *NewHead = new ListNode(0);
    ListNode *marker = NewHead;
    ListNode *temp = nullptr;
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->val <= head2->val)
        {
            marker->next = head1;
            head1 = head1->next;
            marker = marker->next;
            marker->next = nullptr;
        }
        else
        {
            marker->next = head2;
            head2 = head2->next;
            marker = marker->next;
            marker->next = nullptr;
        }
    }

    while (head1)
    {
        marker->next = head1;
        head1 = head1->next;
        marker = marker->next;
        marker->next = nullptr;
    }
    while (head2)
    {
        marker->next = head2;
        head2 = head2->next;
        marker = marker->next;
        marker->next = nullptr;
    }

    lists[storage] = NewHead->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;
    if (lists.size() == 1)
        return lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
        merge(lists, lists[i - 1], lists[i], i);
    }

    return lists.back();
}

// Helper function to print list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Test case 1: Original test
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode *head3 = new ListNode(2);
    head3->next = new ListNode(6);

    vector<ListNode *> lists1 = {head1, head2, head3};
    cout << "Test 1: ";
    ListNode *res1 = mergeKLists(lists1);
    printList(res1);

    // Test case 2: Empty lists
    vector<ListNode *> lists2 = {};
    cout << "Test 2: ";
    ListNode *res2 = mergeKLists(lists2);
    printList(res2);

    // Test case 3: Single node in each list
    ListNode *h1 = new ListNode(1);
    ListNode *h2 = new ListNode(2);
    ListNode *h3 = new ListNode(3);
    vector<ListNode *> lists3 = {h1, h2, h3};
    cout << "Test 3: ";
    ListNode *res3 = mergeKLists(lists3);
    printList(res3);

    // Test case 4: Lists with negative numbers
    ListNode *n1 = new ListNode(-2);
    n1->next = new ListNode(5);
    ListNode *n2 = new ListNode(-1);
    n2->next = new ListNode(0);
    vector<ListNode *> lists4 = {n1, n2};
    cout << "Test 4: ";
    ListNode *res4 = mergeKLists(lists4);
    printList(res4);

    // Test case 5: Lists with duplicates
    ListNode *d1 = new ListNode(1);
    d1->next = new ListNode(1);
    ListNode *d2 = new ListNode(1);
    d2->next = new ListNode(2);
    vector<ListNode *> lists5 = {d1, d2};
    cout << "Test 5: ";
    ListNode *res5 = mergeKLists(lists5);
    printList(res5);

    return 0;
}
