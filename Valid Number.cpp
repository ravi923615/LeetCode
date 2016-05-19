class Solution {
public:
    bool isNumber(string s) {
        if(s.size()==0)
            return 0;
        int i=0;
        int m = s.size()-1;
        int neg = 0;
        int number = 0;
        int countdec = 0,counte = 0;
        while(s[i]==' ')i++;
        if(i==s.size()) return 0;
        while(s[m]==' ')m--;
        if(s[i]=='-' || s[i]=='+'){
            neg = 1;
            i++;
        }
        if(s[i]=='e' || s[m]=='e') return 0;
        if(i==m && s[i]=='.') return 0;
        for(int j=i;j<=m;j++){
            if((s[j]>='0' && s[j]<='9') && countdec<=1 && counte<=1){
                number = number*10 + s[j]-'0';
            }else if(s[j]==' ') return 0;
            else if(s[j]=='.' && counte==0){
                 if(s[j+1]=='e' && (j+1==m||j==i))
                    return 0;
                 countdec++;
            }
            else if(s[j]=='e'){
                if(s[j+1]=='.')
                    return 0;
                if((s[j+1]=='+' || s[j+1]=='-') && j+1<m)
                    j++;
                counte++;
            }
            else return 0;
            if(countdec>1 || counte>1) 
                return 0;
        }
        return 1;
    }
};