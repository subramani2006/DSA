/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "#";  // null marker

        return to_string(root->val) + "," +
               serialize(root->left) + "," +
               serialize(root->right);
    }

    // Helper for deserialization
    TreeNode* deserializeHelper(stringstream& ss) {
        string value;
        getline(ss, value, ',');  // read until comma

        if (value == "#") return NULL;

        TreeNode* node = new TreeNode(stoi(value));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};
