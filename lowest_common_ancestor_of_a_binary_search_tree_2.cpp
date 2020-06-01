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
        auto pVal{p->val};
        auto qVal{q->val};
        
        while (root != nullptr) {
            auto rootVal{root->val};
            
            if (rootVal > pVal && rootVal > qVal) {
                root = root->left;
            } else if (rootVal < pVal && rootVal < qVal) {
                root = root->right;
            } else {
                return root;
            }
        }
        
        return root;
    }
};
