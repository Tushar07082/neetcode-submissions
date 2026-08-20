class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prodFromStart(n, 1);
        prodFromStart[0] = nums[0];
        for(int i=1;i< n;i++){
            prodFromStart[i] = prodFromStart[i-1]*nums[i];
        }

        vector<int> prodFromEnd(n);
        prodFromEnd[n-1] = nums.back();
        for(int i=n-2;i >= 0;i--){
            prodFromEnd[i] = prodFromEnd[i+1]*nums[i];
        }

        vector<int> answer(n);
        answer[0] = prodFromEnd[1];
        answer[n-1] = prodFromStart[n-2];
        for(int i=1;i<nums.size()-1;i++){
            answer[i] = prodFromStart[i-1]*prodFromEnd[i+1];
        }

        return answer;

    }
};
