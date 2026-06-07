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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front(); q.pop();
            if(!node) {
                str += "*."; continue;
            }
            else str += to_string(node->val) + ".";
            q.push(node->left); q.push(node->right);
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int n = data.size(), i = 0;

        auto getVal = [&]() {
            int j = i;
            while(j < n && data[j] != '.') ++j;
            string str = data.substr(i, j-i);
            i = j+1;
            if(str == "*") return -1001;
            return stoi(str);
        };

        int rootVal = getVal();
        if(rootVal == -1001) return nullptr;
        TreeNode* root = new TreeNode(rootVal);

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front(); q.pop();

            int leftVal = getVal(), rightVal = getVal();
            if(leftVal >= -1000) node->left = new TreeNode(leftVal);
            if(rightVal >= -1000) node->right = new TreeNode(rightVal);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return root;
    }
};