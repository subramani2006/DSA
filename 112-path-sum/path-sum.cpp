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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        queue<pair<TreeNode*, int>> q;
        q.push({root, targetSum - root->val});

        while (!q.empty()) {
            auto [node, sum] = q.front();
            q.pop();

            // If it's a leaf and sum is 0 → path found
            if (!node->left && !node->right && sum == 0) {
                return true;
            }

            if (node->left) {
                q.push({node->left, sum - node->left->val});
            }
            if (node->right) {
                q.push({node->right, sum - node->right->val});
            }
        }

        return false;
    }
};

