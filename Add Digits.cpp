class Solution {
public:
    int addDigits(int num) {
        if(num<0)
            return num;
        int sum = 0;
        sum = 1 + (num-1)%9;
        return sum;
    }
};