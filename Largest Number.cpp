class Solution {
public:
    static bool getMax(string a,string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        
        vector<string> num;
        string out; 
        //creating the array of number in form of string.
        for(int i=0;i<nums.size();i++)
            num.push_back(to_string(nums[i]));

        // A custom sort method defined to push the integer ahead which will creater 
        // greater number.
        std::sort(num.begin(),num.end(),getMax);

        // Concatenate the number after custom sorting is finished.
        for(int j=0;j<num.size();j++)
            out += num[j];
        int m = 0;
        // To skip trailing zeros.
        while(out[m]=='0') m++;
        if(m==out.size())
            return "0";
        return out.substr(m);
    }
};