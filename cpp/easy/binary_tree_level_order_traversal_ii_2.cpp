/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> output;
        
        if (root == nullptr) {
            return output;
        }
        
        queue<TreeNode *> nodes;
        vector<int> buffer;
        
        nodes.push(root);
        nodes.push(nullptr);
        
        while (!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();
            
            if (node == nullptr) {
                if (!nodes.empty()) {
                    nodes.push(nullptr);
                }
                
                output.push_back(buffer);
                buffer.clear();
                continue;
            }
            
            if (node->left != nullptr) {
                nodes.push(node->left);
            }
            
            if (node->right != nullptr) {
                nodes.push(node->right);
            }
            
            buffer.push_back(node->val);
        }
        
        reverse(output.begin(), output.end());
        return output;
    }
};
