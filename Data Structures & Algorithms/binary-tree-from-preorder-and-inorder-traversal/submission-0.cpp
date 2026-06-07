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
    unordered_map<int, int> mp;
    int n;
    vector<int> preorder, inorder;
    TreeNode* solve(int pst, int pend, int ist, int iend) {
        if(pst > pend) return nullptr;
        TreeNode* root = new TreeNode(preorder[pst]);
        int indx = mp[preorder[pst]]; // index of root in inorder 
        int leftSize = indx-ist, rightSize = iend-indx;
        root->left = solve(pst+1, pst+leftSize, ist, indx-1);
        root->right = solve(pst+leftSize+1, pend, indx+1, iend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder; this->inorder = inorder;
        n = inorder.size();
        for(int i=0; i<n; ++i) mp[inorder[i]] = i;
        return solve(0, n-1, 0, n-1);
    }
};
