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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return true;
        }
        
        auto left = helper(root->left, 1);
        auto right = helper(root->right, 1);
        
        if (abs(left - right) > 1) {
            return false;
        }
        
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
    
    int helper(TreeNode* node, int depth) {
        if (node == nullptr) {
            return depth - 1;
        }
        
        auto left = helper(node->left, depth + 1);
        auto right = helper(node->right, depth + 1);
        
        return max(left, right);
    }
};
