class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return 0;
        int n=0,y=x;
        //Reverse the given number.
        while(y!=0){
            n = n*10 + y%10;
            y = y/10;
        }
        cout<<n;
        //if reversed number is same as input number then it is palidrome.
        if(x==n)
            return 1;
        return 0;
    }
};