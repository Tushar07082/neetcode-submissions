class Solution {
public:
    vector<int> bits;
    int hammingWeight(uint32_t n) {
        if(n==0) return 0;
        if(bits[n] != -1) return bits[n];
        int ans = 1 + hammingWeight(n & (n-1));
        return bits[n] = ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        bits.resize(n+1, -1);
        for(int i=0;i<=n;i++){
            ans.push_back(hammingWeight(i));
        }
        return ans;
    }
};
