class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, n = digits.size();
        for(int i=n-1;i>=0;i--){
            if(carry==0) return digits;
            else if(digits[i]==9) digits[i] = 0;
            else{
                digits[i] += carry;
                carry = 0;
            } 
        }
        if(carry != 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
