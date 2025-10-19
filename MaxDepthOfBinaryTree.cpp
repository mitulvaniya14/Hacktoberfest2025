// LeetCode 104: Maximum Depth of Binary Tree
// Solution using recursion (Depth First Search)
// Time Complexity: O(n)

#include <iostream>
#include <algorithm> // For max()

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: an empty tree has a depth of 0
        if (root == nullptr) {
            return 0;
        }
        
        // Recursive step
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // The depth is 1 (for the current node)
        // plus the max depth of the left or right subtree
        return 1 + max(leftDepth, rightDepth);
    }
};

// Main function to test the code
int main() {
    Solution sol;
    
    // Create a sample tree:
    //    3
    //   / \
    //  9  20
    //    /  \
    //   15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "The maximum depth of the tree is: " << sol.maxDepth(root) << endl; // Should be 3

    return 0;
}
