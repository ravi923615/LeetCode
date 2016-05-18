class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string d;
        int neg = 1;
        long long int n,dn;
        if(numerator==0)
            return "0";
        if(denominator==0)
            return "";
        if(numerator<0 ^ denominator<0) d += '-'; 
        n = abs(numerator);
        n = abs(n);
        dn = abs(denominator);
        dn = abs(dn);
        map<int,int> hash;
        long long int remainder = n%dn;
        d +=to_string(n/dn);
        if(remainder)
            d+='.';
        else return d;
        while(remainder!=0){
            if(hash.find(remainder)==hash.end())
                hash[remainder] = d.size();
            else{
                d.insert(hash[remainder],1,'(');
                d += ')';
                break;
            }
            remainder *= 10;
            d += to_string(remainder/dn);
            remainder = remainder%dn;
        }
        return d;
    }
};