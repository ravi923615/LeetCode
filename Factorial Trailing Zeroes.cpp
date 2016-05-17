class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        // Loop to find multiples of 5 present in number determining the zeros.
        while(n!=0){
            count = count + n/5;
            n = n/5;
        }
        return count;
    }
};