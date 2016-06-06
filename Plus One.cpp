class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        int carry=1;
        vector<int> tsum;
        while(carry!=0 || i>=0){
            int sum = digits[i]+carry;
            carry = 0;
            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            }
            tsum.push_back(sum);
            i--;
        }
        reverse(tsum.begin(),tsum.end());
        return tsum;
    }
};