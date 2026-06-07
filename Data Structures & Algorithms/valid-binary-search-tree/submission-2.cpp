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
    bool isValidBST(TreeNode* root, int minVal = -1001, int maxVal = 1001) {
        if(!root) return true;
        return root->val > minVal &&
                root->val < maxVal &&
                isValidBST(root->left, minVal, root->val) &&
                isValidBST(root->right, root->val, maxVal);
    }
};
