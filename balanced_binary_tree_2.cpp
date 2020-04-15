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
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        if (abs(left - right) > 1) {
            return false;
        }
        
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
    
    int helper(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        return max(helper(node->left), helper(node->right)) + 1;
    }
};
