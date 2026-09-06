class Solution {
public:
    void findPermutations(vector<int> &nums, vector<int> &visited, vector<int> &curr, vector<vector<int>> &ans){
        if(curr.size() == visited.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]==false){
                visited[i] = true;
                curr.push_back(nums[i]);
                findPermutations(nums, visited, curr, ans);
                visited[i] = false;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n, false);
        vector<int> curr;
        vector<vector<int>> ans;
        findPermutations(nums, visited, curr, ans);
        return ans;
    }
};
