class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        map<int,int> hash;
        for(int i=0;i<nums2.size();i++)
            hash[nums2[i]]++;
        for(int j=0;j<nums1.size();j++){
            if(hash.find(nums1[j])!=hash.end() && hash[nums1[j]]!=0){
                out.push_back(nums1[j]);
                hash[nums1[j]]=0;
            }
        }
        return out;
    }
};