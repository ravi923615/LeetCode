class Solution{
public:
	int search(vector<int> &inorder,int val){
		for(int i=0;i<inorder.size();i++){
			if(inorder[i]==val)
				return i;
		}
		return -1;
	}
	TreeNode* getBinaryTreeBuild(vector<int> &postorder,vector<int> &inorder,int start,int end,int &postIndex){
		if(start>end)
			return NULL;
		TreeNode* root = new TreeNode(postorder[postIndex--]);
		if(start==end)
			return root;
		int inoIndex = search(inorder,root->val);
		root->right = getBinaryTreeBuild(postorder,inorder,inoIndex+1,end,postIndex);
		root->left = getBinaryTreeBuild(postorder,inorder,start,inoIndex-1,postIndex);
		return root;
	}
	TreeNode* buildTree(vector<int> &postorder,vector<int> &inorder){
		TreeNode* root = NULL;
		int end = inorder.size()-1;
		int postIndex = postorder.size()-1;
		root = getBinaryTreeBuild(postorder,inorder,0,end,postIndex);
		return root;
	}
}