class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) 
            return new TreeNode(val);

        TreeNode* temp = root;
        while (true) {
            if (val > temp->val) {
                if (temp->right != nullptr) {
                    temp = temp->right;
                } else {
                    temp->right = new TreeNode(val);
                    break;
                }
            } else {
                if (temp->left != nullptr) {
                    temp = temp->left;
                } else {
                    temp->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
