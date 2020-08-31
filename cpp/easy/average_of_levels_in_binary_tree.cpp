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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        vector<double> avgs;
        auto sum{0.0};
        auto count{0};
        
        q1.push(root);
        
        while (true) {
            while (!q1.empty()) {
                auto node{q1.front()};
                
                if (node->left != nullptr) {
                    q2.push(node->left);
                }
                
                if (node->right != nullptr) {
                    q2.push(node->right);
                }
                
                sum += node->val;
                count++;
                q1.pop();
            }
            
            avgs.push_back(sum / count);
            sum = 0;
            count = 0;
            if (q2.empty()) {
                return avgs;
            }
            swap(q1, q2);
        }
        
        return avgs;
    }
};
