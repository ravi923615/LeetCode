class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        // Getting XOR solution to find the single number. since all duplicate value will make x as 0. 
        for(int i=0;i<nums.size();i++)
            x ^=nums[i];
        return x;
        
    }
};