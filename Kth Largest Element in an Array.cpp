class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1)
            return nums[0];
        map<int,int> hash;
        for(int i=0;i<nums.size();i++)
            hash[nums[i]]++;
        int j = 0;
        for(map<int,int>::reverse_iterator it=hash.rbegin();it!=hash.rend();++it){
            while(it->second!=0){
                j++;
                it->second--;
                if(j==k)
                    return it->first;
            }
            if(j==k){
                return it->first;
            }
        }
        return -1;
    }
};