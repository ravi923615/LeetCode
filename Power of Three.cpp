class Solution {
public:
    bool isPowerOfThree(int n) {
    	// Since 3486784401u is the maximum power value of 3 before integer flow. Hence all input number divisible by this is power of 3.
         return n != 0 && 3486784401u % n == 0;
    }
};