class Solution{
public:
	/* LOGIC: We need to traverse whole binary tree to get max difference
	If we are at leaf node then just return its value because it can't be
	ancestor of any node.
	Then at each internal node we will try to get minimum value from left
	subtree and right subtree and calculate the difference between node value
	and this minimum value and according to that we will update the result
	As we are calculating minimum value while returning in recurrence we
	will check all optimal possibilities of difference and hence calculate
	result in one Traversal only. */
	int maxDiffUtil(TreeNode* root,int &res){
		//Returning maximum INT value if node is not there
		if(root==NULL)
			return INT_MAX;
		//IF node is leaf node then return it value.
		if(!root->left && !root->right)
			return root->val;

		//Recursively calling left and right subtree for minimum value
		int getVal = min(maxDiffUtil(root->left,res),maxDiffUtil(root->right,res));

		res = max(res,root->val-getVal);

		//Returning minimum value got so far.

		return min(getVal,root->key);

	}

	int maxDifF(TreeNode* root){
		int res = INT_MIN;
		maxDiffUtil(root,&res);
		return res;
	}
}