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
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty()) {
            auto node{q.front()};
            q.pop();
            
            helper(node);
            
            if (node->left != nullptr) {
                q.push(node->left);
            }
            
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        
        return maxLength;
    }
private:
    int maxLength{0};
    
    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        auto leftPath{0};
        auto rightPath{0};
        
        if (root->left != nullptr && root->left->val == root->val) {
            leftPath = helper(root->left) + 1;
        }
        
        if (root->right != nullptr && root->right->val == root->val) {
            rightPath = helper(root->right) + 1;
        }
        
        auto currentLength = max(leftPath, max(rightPath, leftPath + rightPath));
        this->maxLength = max(currentLength, this->maxLength);
        
        return max(leftPath, rightPath);
    }
};
