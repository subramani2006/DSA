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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long minIndex = q.front().second;
            long long first, last;

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();

                long long curIndex = idx - minIndex; 
                if (i == 0) first = curIndex;
                if (i == size - 1) last = curIndex;

                if (node->left) q.push({node->left, curIndex * 2});
                if (node->right) q.push({node->right, curIndex * 2 + 1});
            }
            maxWidth = max(maxWidth, last - first + 1);
        }
        return (int)maxWidth;
        
    }
};