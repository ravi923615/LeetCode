class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;
        if(nums.size()==0)
            return out;
        if(k<=0)
            return nums;
        map<int,int> hash;
        for(int i=0;i<k;i++)
            hash[nums[i]]++;
        int j=0;
        out.push_back((hash.rbegin())->first);
        for(int i=k;i<nums.size();i++){
            if(hash.find(nums[i])==hash.end()){
                if(hash[nums[j]]==1)
                    hash.erase(nums[j++]);
                else
                    hash[nums[j++]]--;
                hash[nums[i]]++;
                out.push_back((hash.rbegin())->first);
            }else{
                if(hash[nums[j]]==1)
                    hash.erase(nums[j++]);
                else
                    hash[nums[j++]]--;
                hash[nums[i]]++;
                out.push_back((hash.rbegin())->first);
            }
        }
        return out;
    }
};