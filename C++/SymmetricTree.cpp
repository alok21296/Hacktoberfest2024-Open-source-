#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check if two trees are mirrors of each other
bool isMirror(TreeNode* t1, TreeNode* t2) {
    // If both nodes are NULL, they are mirrors
    if (t1 == NULL && t2 == NULL) {
        return true;
    }
    // If only one of them is NULL, they are not mirrors
    if (t1 == NULL || t2 == NULL) {
        return false;
    }
    // Check if the current nodes' values are equal and if the left subtree of t1
    // is a mirror of the right subtree of t2 and vice versa
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Main function to check if a tree is symmetric
bool isSymmetric(TreeNode* root) {
    if (root == NULL) {
        return true;  // An empty tree is symmetric
    }
    // Check if the left and right subtrees are mirrors of each other
    return isMirror(root->left, root->right);
}

int main() {
    // Creating a symmetric binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}
