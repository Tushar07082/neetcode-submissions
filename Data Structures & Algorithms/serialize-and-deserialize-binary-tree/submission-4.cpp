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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "N";
        string x = "(" + to_string(root->val) + ")";
        return x + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return deserializePlease(data, idx);
    }

    TreeNode* deserializePlease(const string &data, int &i){
        if(i>=data.size()) return nullptr;
        if(data[i] == 'N') {
            i++;
            return nullptr;
        }else{
            string x = "";
            i++;
            while(data[i] != ')'){
                x += data[i];
                i++;
            }
            int value = stoi(x);
            i++;
            TreeNode * ans = new TreeNode(value);
            ans->left = deserializePlease(data, i);
            ans->right = deserializePlease(data, i);
            return ans;
        }
    }
};
