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
        
        auto count{0};
        helper(root, 0, sum, &count);
        
        return pathSum(root->left, sum) + pathSum(root->right, sum) + count;
    }
    
    void helper(TreeNode* node, int runSum, int target, int* pCount) {
        if (node == nullptr) {
            return;
        }
        
        if (runSum + node->val == target) {
            (*pCount)++;
        }
        
        helper(node->left, runSum + node->val, target, pCount);
        helper(node->right, runSum + node->val, target, pCount);
    }
};
