class Solution{
public:
	int getDepth(TreeNode* root){
		if(root==NULL)
			return 0;
		int lft = getDepth(root->left);
		if(lft==-1)
			return -1;
		int rght = getDepth(root->right);
		if(rght==-1)
			return -1;
		if(abs(rght-lft)>1)
			return -1;
		return max(lft,rght)+1;
	}

	bool isBalanced(TreeNode* root){
		return getDepth(root)==-1?false:true;
	}
}