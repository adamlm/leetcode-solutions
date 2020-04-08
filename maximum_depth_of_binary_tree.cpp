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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        auto max{1};
        helper(root->left, 2, &max);
        helper(root->right, 2, &max);
        
        return max;
    }
    
    void helper(TreeNode* node, int depth, int* max) {
        if (node == nullptr) {
            return;
        }
        
        if (depth > *max) {
            (*max)++;
        }
        helper(node->left, depth + 1, max);
        helper(node->right, depth + 1, max);
    }
};
