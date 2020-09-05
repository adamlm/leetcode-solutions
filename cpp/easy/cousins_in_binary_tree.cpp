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
    bool isCousins(TreeNode* root, int x, int y) {
        auto xDepth{0};
        auto yDepth{0};
        
        auto xParent = findParent(root, x, &xDepth, 0);
        auto yParent = findParent(root, y, &yDepth, 0);
        
        return xParent != yParent && xDepth == yDepth;
    }
    
private:
    TreeNode* findParent(TreeNode* node, int val, int* nDepth, int depth) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (node->left != nullptr && node->left->val == val) {
            *nDepth = depth + 1;
            return node;
        }
        
        if (node->right != nullptr && node->right->val == val) {
            *nDepth = depth + 1;
            return node;
        }
        
        auto left{findParent(node->left, val, nDepth, depth + 1)};
        auto right{findParent(node->right, val, nDepth, depth + 1)};
        
        if (left == nullptr) {
            return right;
        }
        
        return left;
    }
};
