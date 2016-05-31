class Solution {
public:
    bool isUgly(int num) {
        if(num==0)
            return 0;
        int x = num ;
        while(x%2==0){
            x = x/2;
        }
        if(x!=1){
            while(x%3==0) x = x/3;
        }
        if(x!=1){
            while(x%5==0) x = x/5;
        }
        if(x!=1)
            return 0;
        else
            return 1;
    }
};