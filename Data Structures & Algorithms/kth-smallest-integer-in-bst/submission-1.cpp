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
    int findKthSmallest(TreeNode* root, int &i, int k){
        if(root==nullptr) return -1;

        int left = findKthSmallest(root->left, i, k);

        if(left != -1) return left;

        if(i==k) return root->val;
        
        i++;
        return findKthSmallest(root->right, i, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 1;
        return findKthSmallest(root, i, k);
    }
};
