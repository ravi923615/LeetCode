class Solution{
public:
	void getAllParanthesis(std::vector<string> &result,int left,int right,int n,string &out){
		if(start>n){
			return;
		}else if(left==n && right==n){
			result.push_back(out);
		}else{
			getAllParanthesis(result,left+1,right,n,out+"(");
			if(left>right)
				getAllParanthesis(result,left,right+1,out+")");
		}

	}
	vector<string> generateParenthesis(int n){
		vector<string> result;
		if(n==0)
			return result;
		getAllParanthesis(result,0,0,n,"");
		return result;
	}
}