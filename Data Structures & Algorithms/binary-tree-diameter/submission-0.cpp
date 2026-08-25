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
    int findDiameter(TreeNode* root, int &height){
        if(root == nullptr){
            height = 0;
            return 0;
        }
        int leftHeight = 0, rightHeight = 0;
        int leftDiameter = findDiameter(root->left, leftHeight);
        int rightDiameter = findDiameter(root->right, rightHeight);

        height = max(leftHeight, rightHeight) + 1;
        return max(leftHeight+rightHeight, max(leftDiameter, rightDiameter));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        return findDiameter(root, height);
    }
};
