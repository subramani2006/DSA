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
    // Helper: convert integer to string manually
    string intToStr(int num) {
        if(num == 0) return "0";
        string s = "";
        bool neg = false;
        if(num < 0) { neg = true; num = -num; }
        while(num > 0) {
            char c = '0' + (num % 10);
            s = c + s;
            num /= 10;
        }
        if(neg) s = "-" + s;
        return s;
    }

    // Helper: convert string to integer manually
    int strToInt(const string& s) {
        int num = 0, i = 0;
        bool neg = false;
        if(s[0] == '-') { neg = true; i = 1; }
        for(; i < (int)s.size(); i++) {
            num = num * 10 + (s[i] - '0');
        }
        return neg ? -num : num;
    }

    // Encodes a tree to a single string (preorder traversal).
    string serialize(TreeNode* root) {
        if(root == NULL) return "#,";
        return intToStr(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    // Helper for deserialization
    TreeNode* deserializeHelper(vector<string>& tokens, int& idx) {
        if(idx >= (int)tokens.size()) return NULL;
        string val = tokens[idx++];
        if(val == "#") return NULL;

        TreeNode* node = new TreeNode(strToInt(val));
        node->left = deserializeHelper(tokens, idx);
        node->right = deserializeHelper(tokens, idx);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string temp = "";
        for(char c : data) {
            if(c == ',') {
                tokens.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        int idx = 0;
        return deserializeHelper(tokens, idx);
    }
};
