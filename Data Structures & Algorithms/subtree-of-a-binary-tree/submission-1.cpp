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
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot, bool atRoot = true) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val == subRoot->val) {
            if(isSubtree(root->left, subRoot->left, false) && 
                isSubtree(root->right, subRoot->right, false)) return true;
        }
        return atRoot && (isSubtree(root->left, subRoot, true) || 
                isSubtree(root->right, subRoot, true));
    }
};