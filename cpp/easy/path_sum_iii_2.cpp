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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        
        auto count = helper(root, 0, sum);
        
        return pathSum(root->left, sum) + pathSum(root->right, sum) + count;
    }
    
    int helper(TreeNode* node, int runSum, int target) {
        if (node == nullptr) {
            return 0;
        }
        
        const auto equal{runSum + node->val == target? 1: 0};
        
        return helper(node->left, runSum + node->val, target) 
            + helper(node->right, runSum + node->val, target)
            + equal;
    }
};
