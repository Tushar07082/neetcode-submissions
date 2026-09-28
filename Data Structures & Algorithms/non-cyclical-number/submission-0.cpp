class Solution {
public:
    int solve(int n){
        int ans = 0;
        while(n>0){
            ans += (n%10) * (n%10);
            n = n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = solve(n);

        while(fast != 1 && slow != fast) {
            slow = solve(slow);
            fast = solve(solve(fast));
        }

        return fast == 1;
    }
};
