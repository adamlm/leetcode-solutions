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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if ((p == nullptr) != (q == nullptr)) {
            return false;
        }
        
        queue<TreeNode*> pQueue;
        queue<TreeNode*> qQueue;
        
        pQueue.push(p);
        qQueue.push(q);
        
        while (!pQueue.empty() && !qQueue.empty()) {
            TreeNode* pNode = pQueue.front();
            TreeNode* qNode = qQueue.front();
            
            if (pNode->val != qNode->val)
                return false;
            
            if (pNode->left != nullptr && qNode->left != nullptr) {
                pQueue.push(pNode->left);
                qQueue.push(qNode->left);
            } else if ((pNode->left != nullptr) != (qNode->left != nullptr)) {
                return false;
            }
                
            if (pNode->right != nullptr && qNode->right != nullptr) {
                pQueue.push(pNode->right);
                qQueue.push(qNode->right);
            } else if ((pNode->right != nullptr) != (qNode->right != nullptr)) {
                return false;
            }
            
            pQueue.pop();
            qQueue.pop();
        }
        
        if (pQueue.empty() != qQueue.empty()) {
            return false;
        }
        
        return true;
    }
};
