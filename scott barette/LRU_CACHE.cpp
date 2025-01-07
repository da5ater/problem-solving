#include <queue>
#include <unordered_map>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
public:
    int value;
    int key;
    Node *next;
    Node *prev;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache
{
    int capacity;
    int c;
    unordered_map<int, Node *> map;
    Node *left;
    Node *right;

    void insert(Node *node)
    {
        node->prev = right->prev;
        node->next = right;
        right->prev->next = node;
        right->prev = node;
    }

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        c = 0;
        map.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
        {
            return -1;
        }
        else
        {
            Node *temp = map[key];
            remove(temp);
            insert(temp);
            return temp->value;
        }
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            remove(map[key]);
        }

        Node *temp = new Node(key, value);
        insert(temp);
        map[key] = temp;

        if (map.size() > capacity)
        {
            Node *temp = left->next;
            remove(temp);
            map.erase(temp->key);
            delete temp;
        }
    }
};

int main()
{
    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(2, 2);
    assert(cache.get(2) == 2);
    cache.put(1, 1);
    cache.put(4, 1);
    assert(cache.get(2) == -1);

    return 0;
}