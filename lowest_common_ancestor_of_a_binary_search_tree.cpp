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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto pLeft{root->val > p->val};
        auto qLeft{root->val > q->val};
        
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        
        if (pLeft != qLeft) {
            return root;
        }
        
        if (pLeft && qLeft) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        return lowestCommonAncestor(root->right, p, q);
    }
};
