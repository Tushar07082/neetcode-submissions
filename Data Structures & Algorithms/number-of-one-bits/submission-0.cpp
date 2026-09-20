class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 1 , ans = 0;
        while(i <= n){
            ans += bool (i & n) ;
            i = i << 1;
        }
        return ans;
    }
};
