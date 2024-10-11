#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the maximum depth of a binary tree
int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;  // Base case: an empty tree has depth 0
    }
    
    // Recursively calculate the depth of left and right subtrees
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    // The depth of the current node is the maximum of the two subtrees' depths plus 1
    return max(leftDepth, rightDepth) + 1;
}

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "The maximum depth of the binary tree is: " << maxDepth(root) << endl;

    return 0;
}
