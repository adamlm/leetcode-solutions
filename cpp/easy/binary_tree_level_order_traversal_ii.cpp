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
        
        auto current_size{1};
        auto next_size{0};
        
        nodes.push(root);
        
        while (!nodes.empty()) {
            auto node = nodes.front();
            
            if (node->left != nullptr) {
                nodes.push(node->left);
                next_size++;
            }
            
            if (node->right != nullptr) {
                nodes.push(node->right);
                next_size++;
            }
            
            buffer.push_back(node->val);
            current_size--;
            nodes.pop();
            
            if (current_size == 0) {
                output.insert(output.begin(), buffer);
                buffer.clear();
                current_size = next_size;
                next_size = 0;
            }
        }
        
        return output;
    }
};
