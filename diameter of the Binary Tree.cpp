class Solution{

	//Optimized solution.
	TreeNode* getDiameterBinaryTree(TreeNode* root, int &height){
		//lh --> height of left subtree
		//rh --> height of right subtree
		int lh = 0, rh = 0;

		int ldiameter = 0, rdiameter = 0;

		if(root==NULL){
			height = 0;
			return 0;
		}

		ldiameter = getDiameterBinaryTree(root->left,lh);
		rdiameter = getDiameterBinaryTree(root->right,rh);

		height = max(lh,rh)+1;

		return max(lh+rh+1,max(ldiameter,rdiameter));
	}

	// Non Optimized.
	int Diameter(TreeNode* root){
		if(root==NULL)
			return 0;

		//get Height of left and right subtree.
		int lheight = height(root->left);
		int rheight = height(root->rihgt);

		//Get diameter of left and right subtree.
		int ldiameter = Diameter(root->left);
		int rdiameter = Diameter(root->right);

		return max(lheight+rheight+1,max(ldiameter,rdiameter));
	}

	int height(TreeNode* root){
		if(root==NULL)
			return 0;
		return 1+max(height(root->left),height(root->right));
	}
}