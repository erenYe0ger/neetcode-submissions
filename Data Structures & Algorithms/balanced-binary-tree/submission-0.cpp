/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int height(TreeNode* root, bool& bal) {
        if(!root) return 0;
        int left = height(root->left, bal), 
            right = height(root->right, bal);
        bal &= abs(left-right) <= 1;
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool bal = true;
        height(root, bal);
        return bal;
    }
};
