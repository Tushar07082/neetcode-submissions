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
    bool checkBST(TreeNode* root, int mini, int maxi){
        if(root==nullptr) return true;
        
        if(root->val <= mini){
            return false;
        }
        if(root->val >= maxi){
            return false;
        }
        return checkBST(root->left, mini, root->val) && checkBST(root->right, root->val, maxi);
        
    }
    bool isValidBST(TreeNode* root) {
        int mini = INT_MIN, maxi = INT_MAX;
        return checkBST(root, mini, maxi);
    }
};
