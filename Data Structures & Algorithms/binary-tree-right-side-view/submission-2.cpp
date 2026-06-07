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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        typedef pair<TreeNode*, int> P;
        queue<P> q;
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            auto [node, level] = q.front(); q.pop();
            if(res.size() == level) res.push_back(node->val);
            else res[level] = node->val;
            if(node->left) q.push(make_pair(node->left, level+1));
            if(node->right) q.push(make_pair(node->right, level+1));
        }
        return res;
    }
};
