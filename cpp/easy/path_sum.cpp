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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        
        auto difference = sum - root->val;
        auto left = root->left;
        auto right = root->right;
        
        if (left == nullptr && right == nullptr && difference == 0) {
            return true;
        }
        
        return hasPathSum(left, difference) || hasPathSum(right, difference);
    }
};
