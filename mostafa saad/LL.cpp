#include <iostream>
#include <assert.h>

using namespace std;

struct Node
{
    int value;
    Node *next;
    int length;

    Node(int value) : value{value}
    {
        next = nullptr;
        length++;
    };

    ~Node()
    {
        cout << "Destroy value " << value << "at " << this << endl;
    }
};

void print(Node *head)
{
    while (head)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void print_recusive(Node *head)
{
    if (head == nullptr)
    {
        cout << endl;
        return;
    }
    cout << head->value << " ";
    print_recusive(head->next);
}

void reverse_print_recusive(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    reverse_print_recusive(head->next);
    cout << head->value << " ";
}

void print_for(Node *head)
{
    for (int i = 0; i < head->length; i++)
    {
        cout << head->value << endl;
        head = head->next;
    }
    cout << endl;
}

Node *find(Node *head, int value)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->value == value)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return nullptr;
}

class LL
{
public:
    Node *head;
    Node *tail;

    LL(int value)
    {
        Node *NewNode = new Node(value);
        head = NewNode;
        tail = NewNode;
    }

    LL(const LL &) = delete;
    LL &operator=(const LL &another) = delete;

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void for_print()
    {
        for (Node *temp = head; temp; temp = temp->next)
        {
            cout << temp->value << " ";
        }
        cout << endl;
    }

    void append(int value)
    {
        Node *NewNode = new Node(value);
        if (!head)
        {
            head = tail = NewNode;
        }
        tail->next = NewNode;
        tail = tail->next;
    }

    Node *get_nth(int index)
    {
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

    Node *get_nth_v_2(int index)
    {
        int curr = 0;
        for (Node *temp = head; temp; temp = temp->next)
        {
            if (++curr == index)
            {
                return temp;
            }
        }
        return nullptr;
    }

    int find(int value)
    {
        int index = 0;
        for (Node *temp = head; temp; temp = temp->next, index++)
        {

            if (temp->value == value)
            {
                return index;
            }
        }
        return -1;
    }

    int find_improved(int value)
    {
        int index = 0;
        Node *prev = nullptr;
        for (Node *temp = head; temp; temp = temp->next, index++)
        {
            if (temp->value == value)
            {
                if (!prev)
                    return index;
                swap(temp->value, prev->value);
                return index - 1;
            }

            prev = temp;
        }
        return -1;
    }

    int find_improved_v_2(int value)
    {
        int index = 0;

        for (Node *temp = head, *prev = nullptr; temp; prev = temp, temp = temp->next)
        {
            if (temp->value == value)
            {
                if (!prev)
                    return index;
                swap(temp->value, prev->value);
                return index - 1;
            }
            index++;
        }
        return -1;
    }

    bool f(Node *node)
    {
        return !node || !node->next || node->value > node->next->value && f(node->next);
    }
    bool f()
    {
        return f(head);
    }
};

int main()
{
    LL *MyLL = new LL(25);
    MyLL->append(20);
    MyLL->append(15);
    MyLL->append(7);
    MyLL->append(10);

    cout << MyLL->f();
}