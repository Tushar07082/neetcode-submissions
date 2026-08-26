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
    int findMaxPathSum(TreeNode* root, int &maxSum){
        if (root == nullptr)
            return 0;

        int left = max(0, findMaxPathSum(root->left, maxSum));
        int right = max(0, findMaxPathSum(root->right, maxSum));

        // Best path passing through this node
        maxSum = max(maxSum, root->val + left + right);

        // Best path that can be extended to parent
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
         int maxSum = INT_MIN;
        findMaxPathSum(root, maxSum);
        return maxSum;
    }
};
