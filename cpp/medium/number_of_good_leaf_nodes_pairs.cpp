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
private:
    int count{0};
    
public:
    int countPairs(TreeNode* root, int distance) {
        helper(root, distance);
        
        return this->count;
    }
    
    vector<int> helper(TreeNode* node, const int distance) {
        vector<int> output(11, 0);
        
        if (node == nullptr) {
            return output;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            output[1] = 1;
            return output;
        }
        
        vector<int> left = helper(node->left, distance);
        vector<int> right = helper(node->right, distance);
        
        for (auto i{0}; i < 11; i++) {
            for (auto j{0}; i + j <= distance; j++) {
                this->count += left[i] * right[j];
            }
        }
        
        for (auto i{0}; i < 10; i++) {
            output[i + 1] += left[i] + right[i];
        }
        
        return output;
    }
};
