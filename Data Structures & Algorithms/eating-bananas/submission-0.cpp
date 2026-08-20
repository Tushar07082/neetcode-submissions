class Solution {
public:
    long long hoursNeeded(vector<int> & piles, int speed){
        long long ans = 0;
        for(long long pile: piles){
            ans += (pile + speed - 1) / speed;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minAns = 1, maxAns = *max_element(piles.begin(), piles.end());

        int ans = maxAns;
        while(minAns<=maxAns){
            int mid = minAns + (maxAns-minAns)/2;
            long long hoursNeededAtMidSpeed = hoursNeeded(piles, mid);
            if(hoursNeededAtMidSpeed  <= h){
                ans = mid;
                maxAns = mid -1;
            }else{
                minAns = mid+1;
            }
        }

        return ans;
    }
};