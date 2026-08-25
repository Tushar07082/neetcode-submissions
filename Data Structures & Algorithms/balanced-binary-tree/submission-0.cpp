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
    bool isHeightDifferenceNotMoreThan1(TreeNode* root, int &height){
        if(root == nullptr) {
            height = 0;
            return true;
        }
        int leftHeight = 0, rightHeight = 0;
        bool isLeftBalanced = isHeightDifferenceNotMoreThan1(root->left, leftHeight);
        bool isRightBalanced = isHeightDifferenceNotMoreThan1(root->right, rightHeight);

        height = max(leftHeight, rightHeight) +1;
        return isLeftBalanced && isRightBalanced && abs(leftHeight-rightHeight) <= 1;

    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isHeightDifferenceNotMoreThan1(root, height);
    }
};
