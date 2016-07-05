class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        vector<int> out;
        if(nums1.size()==0 || nums2.size()==0)
            return out;
        if(nums1.size()<nums2.size())
            swap(nums1,nums2);
        map<int,int> hash;
        for(int i=0;i<nums1.size();i++)
            hash[nums1[i]]++;
        while(i<nums2.size()){
            if(hash.find(nums2[i])!=hash.end() && hash[nums2[i]]!=0){
                hash[nums2[i]]--;
                out.push_back(nums2[i]);
            }
            i++;
        }
        return out;
    }
};