class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int num = words.size();
        int len = words[0].size();
        if(num==0)return result;
        map<string,int> hash;
        for(int i=0;i<words.size();i++)hash[words[i]]++;
        int i=0;
        while((i+num*len-1)<s.size()){
            map<string,int> hash2;
            int j=0;
            while(j<num){
                string sub = s.substr(i+j*len,len);
                //cout<<sub<<" "<<i<<" "<<j*len<<" "<<len<<endl;
                if(hash.find(sub)==hash.end())
                    break;
                else{
                    hash2[sub]++;
                    if(hash2[sub]>hash[sub])
                        break;
                }
                j++;
            }
            if(j==num) result.push_back(i);
            i++;
        }
        return result;
    }
};