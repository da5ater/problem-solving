#include <iostream>

using namespace std;

struct Node

{

  int value;

  Node *next;

  Node(int value) : value{value}, next{nullptr} {};
  ~Node()
  {

    cout << "Destroy value " << value << "at " << this << endl;
  }
};

class LL

{

private:
  Node *head;

  Node *tail;

public:
  LL(int value)
  {

    Node *NewNode = new Node(value);

    head = NewNode;

    tail = NewNode;
  }

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

  void insert(int value)
  {

    Node *NewNode = new Node(value);

    if (!head)

    {

      head = tail = NewNode;
    }
    else
    {
      tail->next = NewNode;

      tail = tail->next;
    }
  }

  void insert_end(int value)
  {
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
  }
};

int main()
{
  LL *MyLL = new LL(2);
  MyLL->insert(3);
  MyLL->insert(4);
  MyLL->insert(5);

  MyLL->insert_end(1);

  MyLL->print();
}