#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode *root, int &targetSum, int &count)
{
    if (!root)
    {
        return false;
    }

    count += root->val;

    if (!root->left && !root->right)
    {
        if (count == targetSum)
            return true;
    }

    if (dfs(root->left, targetSum, count))
    {
        return true;
    };

    if (dfs(root->right, targetSum, count))
        return true;

    count -= root->val;
    return false;
};

bool hasPathSum(TreeNode *root, int targetSum)
{
    int count = 0;
    return dfs(root, targetSum, count);
}

int main()
{
    // Test Case 1: [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(11);
    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right->right->right = new TreeNode(1);

    cout << "Test 1: " << (hasPathSum(root1, 22) ? "true" : "false") << endl;
    // Expected: true

    // Test Case 2: [1,2,3], targetSum = 5
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << "Test 2: " << (hasPathSum(root2, 5) ? "true" : "false") << endl;
    // Expected: false

    // Test Case 3: [], targetSum = 0
    TreeNode *root3 = nullptr;

    cout << "Test 3: " << (hasPathSum(root3, 0) ? "true" : "false") << endl;
    // Expected: false

    TreeNode *root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    cout << "Test 4: " << (hasPathSum(root4, 1) ? "true" : "false") << endl;
    return 0;
}