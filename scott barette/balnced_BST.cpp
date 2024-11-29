#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
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

int calc_height(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    else
    {
        return 1 + std::max(calc_height(root->left), calc_height(root->right));
    }
}

// Function to traverse the BST and perform operations on each node
bool isBalanced(TreeNode *root)
{
    if (!root)
    {
        return true;
    }
    int height = calc_height(root->left) - calc_height(root->right);

    if (abs(height) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    // Create a simple BST for demonstration
    TreeNode *root = new TreeNode(10, "Root");
    root->left = new TreeNode(5, "Left Child");
    root->right = new TreeNode(15, "Right Child");

    root->left->left = new TreeNode(3, "Left-Left Child");
    root->left->right = new TreeNode(7, "Left-Right Child");
    root->left->right->right = new TreeNode(8, "Left-Right Child");
    root->left->right->right = new TreeNode(9, "Left-Right Child");

    // Traverse and process the BST
    std::cout << "Traversing the BST:" << std::endl;
    assert(isBalanced(root) == true);
    cout << isBalanced(root);
    // Cleanup (not strictly necessary in this example but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
