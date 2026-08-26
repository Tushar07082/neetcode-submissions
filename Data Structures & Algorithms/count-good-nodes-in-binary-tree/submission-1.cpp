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
    int findGoodNodes(TreeNode * root, int &maxTillNow){
        if(root==nullptr) return 0;
        int ans = 0;

        if(maxTillNow <= root->val){
            maxTillNow = root->val;
            ans++;
        }
        int leftMax = maxTillNow;
        int rightMax = maxTillNow;
        ans += findGoodNodes(root->left, leftMax) + findGoodNodes(root->right, rightMax);
        return ans;
    }
    int goodNodes(TreeNode* root) {
        int maxTillNow = INT_MIN;
        return findGoodNodes(root, maxTillNow);
    }
};
