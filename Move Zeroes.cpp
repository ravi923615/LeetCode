class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0)
            return;
        int szofarr = nums.size();
        int cur_size = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                nums[cur_size++] = nums[i];
        }
        for(int j=cur_size;j<nums.size();j++)
            nums[j] = 0;
    }
};