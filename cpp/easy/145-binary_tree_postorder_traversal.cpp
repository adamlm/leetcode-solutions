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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return std::vector<int>{};
        }

        auto left_nodes { postorderTraversal(root->left) };
        auto right_nodes { postorderTraversal(root->right) };
        left_nodes.insert(std::cend(left_nodes), std::move_iterator(std::cbegin(right_nodes)), std::move_iterator(std::cend(right_nodes)));
        left_nodes.push_back(root->val);

        return left_nodes;
    }
};

