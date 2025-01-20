#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    // Default constructor
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    // Constructor with value
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    // Constructor with value and neighbors
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// Helper function to print the graph (for debugging purposes)
void printGraph(Node *node)
{
    if (!node)
        return;

    // To keep track of visited nodes and avoid cycles
    unordered_map<Node *, bool> visited;

    // Queue for BFS traversal
    queue<Node *> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << "Node " << current->val << " -> ";
        for (Node *neighbor : current->neighbors)
        {
            cout << neighbor->val << " ";
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        cout << endl;
    }
};

//--------------------------

// Node *DFS(Node *node, unordered_map<Node *, Node *> &set)
// {
//     if (set.count(node) != 0)
//         return set[node];

//     Node *NewNode = new Node(node->val);
//     cout << "Cloning node with value: " << node->val << endl;
//     set[node] = NewNode;

//     for (auto &neighbour : node->neighbors)
//     {
//         cout << "Visiting neighbor with value: " << neighbour->val << endl;
//         NewNode->neighbors.push_back(DFS(neighbour, set));
//     }

//     return node;
// };

// Node *cloneGraph(Node *node)
// {
//     if (!node)
//         return nullptr;
//     unordered_map<Node *, Node *> set;
//     return DFS(node, set);
// }

Node *cloneGraph(Node *node)
{
    if (!node)
        return nullptr;
    unordered_map<Node *, Node *> oldToNew;
    queue<Node *> q;

    oldToNew[node] = new Node(node->val);
    q.push(node);

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        for (auto &neighbour : curr->neighbors)
        {
            if (oldToNew.count(neighbour) == 0)
            {
                oldToNew[neighbour] = new Node(neighbour->val);
                q.push(neighbour);
            }
            oldToNew[curr]->neighbors.push_back(oldToNew[neighbour]);
        }
    }
    return oldToNew[node];
};

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    // Clone the graph
    Node *clonedGraph = cloneGraph(node1);

    // Print the original and cloned graphs
    cout << "Original graph:" << endl;
    printGraph(node1);

    cout << "Cloned graph:" << endl;
    printGraph(clonedGraph);
}