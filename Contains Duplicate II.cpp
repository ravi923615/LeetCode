class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0)
            return 0;
        map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i])==hash.end()){
                hash[nums[i]] = i;
            }else{
                if(abs(hash[nums[i]]-i)<=k)
                    return 1;
                else
                    hash[nums[i]] = i;
            }
        }
        return 0;
        
    }
};