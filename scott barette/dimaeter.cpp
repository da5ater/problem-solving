#include <iostream>
#include <string>
#include <algorithm>

// Definition for a binary tree node
struct TreeNode
{
    int key;         // Corresponds to node-key in Lisp
    std::string val; // Corresponds to node-val in Lisp
    TreeNode *left;  // Left subtree
    TreeNode *right; // Right subtree

    // Constructors
    TreeNode() : key(0), val(""), left(nullptr), right(nullptr) {}
    TreeNode(int k, std::string v) : key(k), val(v), left(nullptr), right(nullptr) {}
    TreeNode(int k, std::string v, TreeNode *left, TreeNode *right)
        : key(k), val(v), left(left), right(right) {}
};

int height(TreeNode *root, int &max)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left_height = height(root->left, max);
    int right_height = height(root->right, max);
    max = std::max(max, left_height + right_height);
    return 1 + std::max(left_height, right_height);
}

// Function to traverse the BST and perform operationlets on each node
int diameterOfBinaryTree(TreeNode *root)
{
    int max = 0;

    height(root, max);
    return max;
}

int main()
{
    // Create a simple BST for demonstration
    TreeNode *root = new TreeNode(10, "Root");
    root->left = new TreeNode(5, "Left Child");
    root->right = new TreeNode(15, "Right Child");

    root->left->left = new TreeNode(3, "Left-Left Child");
    root->left->right = new TreeNode(7, "Left-Right Child");

    // Traverse and process the BST
    std::cout << "Traversing the BST:" << std::endl;
    fn_for_bst(root);

    // Cleanup (not strictly necessary in this example but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
