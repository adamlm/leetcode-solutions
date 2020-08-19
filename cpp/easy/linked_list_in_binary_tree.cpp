/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            auto node = q.front();
            
            if (node->val == head->val && checkTree(head, node)) {
                return true;
            }
            
            if (node->left != nullptr) {
                q.push(node->left);
            }
            
            if (node->right != nullptr) {
                q.push(node->right);
            }
            
            q.pop();
        }
        
        return false;
    }
    
    bool checkTree(ListNode* element, TreeNode* node) {
        if (element->next == nullptr) {
            return true;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            return false;
        }
        
        
        auto left{false};
        if (node->left != nullptr && node->left->val == element->next->val) {
            left = checkTree(element->next, node->left);
        }
        
        auto right{false};
        if (node->right != nullptr && node->right->val == element->next->val) {
            right = checkTree(element->next, node->right);
        }
        
        return left || right;
    }
};
