class Solution {
public:
    bool isHappy(int n) {
        map<int,int> hash;
        int sum = n;
        while(sum!=1){
            int num = sum;
            sum  = 0;
            if(hash.find(num)==hash.end()){
                hash[num]++;
                while(num!=0){
                    int x = num%10;
                    sum += x*x;
                    num = num/10;
                }
            }else{
                break;
            }
        }
        if(sum!=1)
            return 0;
        return 1;
    }
};