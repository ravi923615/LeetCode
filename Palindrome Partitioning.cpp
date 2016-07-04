class Solution {
public:
    bool ispalindrome(string s,int start,int end)
    {
        while(start<end){
            if(s[start]!=s[end])
                return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
    void getPalindromePartition(string A,int start,int end,vector<vector<string>> &out,vector<string> &res){
        if(start>=end){
            out.push_back(res);
        }else{
            for(int i=start;i<end;i++){
                if(ispalindrome(A,start,i)){
                    res.push_back(A.substr(start,i-start+1));
                    getPalindromePartition(A,i+1,end,out,res);
                    res.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> res;
        vector<vector<string>> out;
        getPalindromePartition(s,0,s.size(),out,res);
        return out;
    }
};