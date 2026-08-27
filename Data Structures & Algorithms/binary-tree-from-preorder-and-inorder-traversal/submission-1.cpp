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
    TreeNode* getTreeRoot(vector<int> &preorder, vector<int> &inorder, int start, int end, int &preOrderIdx, unordered_map <int,int> &inorderIdx){
        if(start > end) return nullptr;

        
        TreeNode* ans = new TreeNode(preorder[preOrderIdx]);
        preOrderIdx++;


        int leftEnd = inorderIdx[ans->val]-1;
        ans->left = getTreeRoot(preorder, inorder, start, leftEnd, preOrderIdx, inorderIdx);
        ans->right = getTreeRoot(preorder, inorder, leftEnd+2, end, preOrderIdx, inorderIdx);
        return ans;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIdx;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            inorderIdx[inorder[i]] = i;
        }
        int preOrderIdx = 0;
        return getTreeRoot(preorder, inorder, 0, n-1, preOrderIdx, inorderIdx);
    }
};
