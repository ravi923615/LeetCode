class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();
        if(len1==0&&len2==0)return "0";
        else if(len1==0)return b;
        else if(len2==0)return a;
        if(len1<len2) swap(a,b);
        int i=b.size()-1,j=a.size()-1;
        int carry = 0;
        string out;
        int sum = 0;
        while(i>=0){
            sum = 0;
            int num = a[j--]-'0';
            sum = num+(b[i]-'0')+carry;
            carry = 0;
            if(sum==2){
                sum = 0;
                carry = 1;
            }else if(sum==3){
                sum = 1;
                carry = 1;
            }
            out = to_string(sum) + out;
            i--;
        }if(carry!=0){
            while(carry!=0 && j>=0){
                int num = a[j--]-'0'+carry;
                carry = 0;
                if(num==2){
                    num = 0;
                    carry = 1;
                }
                out = to_string(num) + out;
            }
            if(carry==1)
                out = to_string(carry)+out;
        }if(j>=0){
            while(j>=0)
                out = a[j--] + out;
        }
        int x=0;
        while(out[x]=='0')x++;
        if(x==out.size())return "0";
        return out.substr(x);
        
    }
};