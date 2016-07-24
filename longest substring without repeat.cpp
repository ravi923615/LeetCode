class Solution{
public:
	int lengthOfLongestSubstring(string s){
		int start = 0, end=0;
		int longest = 0;

		//Hash which tracks the count of each character in current window
		// we need to make sure that for solution, none of the 
		// character cout/hash value exceeds 1.
		int hash[260];
		memset(hash,0,sizeof(hash));
		while(start<=end && end<s.size()){
			hash[s[end]]++;
			if(hash[s[end]]>1){
				//pop stuff out of hash till the count becomes 1.
				while(start<=end && hash[s[end]]>1){
					hash[s[start]]--;
					start++;
				}
			}
			end++;
			longest = max(longest,end-start);
		}
		return longest;
	}
}