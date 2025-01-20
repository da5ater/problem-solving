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

    // Constructor with value
    Node(int _val) : val(_val) {}

    // Constructor with value and neighbors
    Node(int _val, vector<Node *> _neighbors) : val(_val), neighbors(_neighbors) {}

    unordered_map<int, vector<int>> adj_list;
    unordered_set<int> visit;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        for (int i = 0; i < numCourses; i++)
        {
            adj_list[i] = {};
        }

        for (auto prereq : prerequisites)
        {
            adj_list[prereq[0]].push_back(prereq[1]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i))
            {
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(int course)
    {
        if (visit.count(course))
        {
            return false;
        }
        if (adj_list[course].empty())
        {
            return true;
        }

        visit.insert(course);
        for (int prereq : adj_list[course])
        {
            if (!dfs(prereq))
            {
                return false;
            }
        }

        visit.erase(course);
        adj_list[course] = {};
        return true;
    }
};

int main()
{
    Node node(0);

    // Test case 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Test case 1: " << (node.canFinish(numCourses1, prerequisites1) ? "Can finish" : "Cannot finish") << endl;

    // Test case 2
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Test case 2: " << (node.canFinish(numCourses2, prerequisites2) ? "Can finish" : "Cannot finish") << endl;

    // Test case 3
    int numCourses3 = 4;
    vector<vector<int>> prerequisites3 = {{1, 0}, {2, 1}, {3, 2}};
    cout << "Test case 3: " << (node.canFinish(numCourses3, prerequisites3) ? "Can finish" : "Cannot finish") << endl;

    // Test case 4
    int numCourses4 = 3;
    vector<vector<int>> prerequisites4 = {{1, 0}, {2, 0}, {0, 2}};
    cout << "Test case 4: " << (node.canFinish(numCourses4, prerequisites4) ? "Can finish" : "Cannot finish") << endl;

    return 0;
}