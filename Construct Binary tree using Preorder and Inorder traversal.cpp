class Solution{
public:
	int searchInInorder(vector<int> &inorder,int val){
		for(int i=0;i<inorder.size();i++){
			if(inorder[i]==val)
				return i;
		}
		return -1;
	}
	TreeNode* getBinaryTree(vector<int> &preorder,vector<int> &inorder,int start,int end, int &preIndex){
		if(start>end)
			return NULL;
		TreeNode* root = new TreeNode(preorder[preIndex++]);
		if(start==end)
			return root;
		int inIndex = searchInInorder(inorder,root->val);
		root->left = getBinaryTree(preorder,inorder,start,inIndex-1,preIndex);
		root->right = getBinaryTree(preorder,inorder,inIndex+1,end,preIndex);
		return root;
	}
	TreeNode* buildTree(vector<int> &preorder,vector<int> &inorder){
		TreeNode* root=NULL;
		int preIndex = 0;
		int end = inorder.size()-1;
		root = getBinaryTree(preorder,inorder,0,end,preIndex);
		return root;
	}
}