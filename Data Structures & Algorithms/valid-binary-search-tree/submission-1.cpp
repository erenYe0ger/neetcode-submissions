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
    int findMax(TreeNode* root) {
        if(!root) return -1001;
        return max({root->val,
                     findMax(root->left), 
                     findMax(root->right)});
    }
    int findMin(TreeNode* root) {
        if(!root) return 1001;
        return min({root->val, 
                    findMin(root->left), 
                    findMin(root->right)});
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return findMax(root->left) < root->val && 
                root->val < findMin(root->right) && 
                isValidBST(root->left) &&
                isValidBST(root->right);
    }
};
