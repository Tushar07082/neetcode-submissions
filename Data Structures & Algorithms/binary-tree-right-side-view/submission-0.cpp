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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};

        queue<TreeNode*> q;
        vector<int> ans;

        q.push(root);

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* x = q.front();q.pop();
                if(i==n-1){
                    ans.push_back(x->val);
                }
                if(x->left != nullptr) q.push(x->left);
                if(x->right != nullptr) q.push(x->right);
            }
        }
        return ans;
    }
};
