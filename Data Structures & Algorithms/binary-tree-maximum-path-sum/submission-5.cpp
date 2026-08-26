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
    int findMaxPathSum(TreeNode* root, int &sumTillRoot){
        if(root==nullptr) return INT_MIN;
        if(root->left == nullptr && root->right == nullptr){
            sumTillRoot = root->val;
            return root->val;
        }

        int leftSumTillRoot = 0;
        int leftMaxPathSum = findMaxPathSum(root->left, leftSumTillRoot);

        int rightSumTillRoot = 0;
        int rightMaxPathSum = findMaxPathSum(root->right, rightSumTillRoot);

        sumTillRoot = max(root->val, max(leftSumTillRoot, rightSumTillRoot) + root->val);

        return max(root->val, max(root->val+leftSumTillRoot, max(root->val + rightSumTillRoot, max(root->val + rightSumTillRoot + leftSumTillRoot, max(leftMaxPathSum, rightMaxPathSum)))));
    }
    int maxPathSum(TreeNode* root) {
        int sumTillRoot = 0;
        return findMaxPathSum(root, sumTillRoot);
    }
};
