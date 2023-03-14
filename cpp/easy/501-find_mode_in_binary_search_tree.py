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
    vector<int> findMode(TreeNode* root) {
        std::unordered_map<int, int> counts;

        countVals(root, counts);

        auto max_val = 0;
        for (const auto& [key, val] : counts) {
            max_val = std::max(max_val, val);
        }

        std::vector<int> modes;
        for (const auto& [key, val] : counts) {
            if (val == max_val) {
                modes.push_back(key);
            }
        }

        return modes;
    }

    auto countVals(const TreeNode const* root, std::unordered_map<int, int>& counts) -> void {
        if (root == nullptr) {
            return;
        }

        counts[root->val] += 1;

        countVals(root->left, counts);
        countVals(root->right, counts);
    }
};

