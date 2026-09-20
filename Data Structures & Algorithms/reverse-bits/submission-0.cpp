class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        uint32_t x = 1;
        for(int i=0;i<32;i++){
            ans = ans*2 + (bool)(x&n);
            // cout<<(x&n)<<" "<<ans<<endl;
            x = x<<1;
        }
        return ans;
    }
};
