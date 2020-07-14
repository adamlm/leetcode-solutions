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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        
        if (root == nullptr) {
            return paths;
        }
        
        paths.emplace_back(to_string(root->val));
        string start = paths.back();
        
        if (root->left != nullptr) {
            helper(root->left, paths);
        }
        
        if (root->left == nullptr && root->right != nullptr) {
            helper(root->right, paths);
        } else if (root->right != nullptr) {
            paths.emplace_back(start);
            helper(root->right, paths);
        }
        
        return paths;
    }
    
    void helper(TreeNode* node, vector<string>& paths) {
        paths.back() += "->" + to_string(node->val);
        string start = paths.back();
        
        if (node->left != nullptr) {
            helper(node->left, paths);
        }
        
        if (node->left == nullptr && node->right != nullptr) {
            helper(node->right, paths);
        } else if (node->right != nullptr) {
            paths.emplace_back(start);
            helper(node->right, paths);
        }
    }
};
