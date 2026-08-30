class Solution {
public:
    void findCombinations(vector<int> &candidates, int i, int target, vector<int> &curr, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(i>=candidates.size()) return;

        if(candidates[i] <= target){
            curr.push_back(candidates[i]);
            findCombinations(candidates, i+1, target-candidates[i], curr, ans);
            curr.pop_back();
        }
        while(i<candidates.size()-1 && candidates[i] == candidates[i+1]){
            i++;
        }
        findCombinations(candidates, i+1, target, curr, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        findCombinations(candidates, 0, target, curr, ans);
        return ans;
    }
};
