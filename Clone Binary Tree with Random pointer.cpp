class Solution{
public:
	void copyRandomPointer(TreeNode* root,TreeNode* newTree,map<TreeNode*,TreeNode*> &hash){
		if(root==NULL)
			return NULL;
		newTree->random = hash[root->random];
		copyRandomPointer(root->left,newTree->left,hash);
		copyRandomPointer(root->right,newTree->right,hash);
	}



	TreeNode* copyLeftRightTree(TreeNode* root,map<TreeNode*,TreeNode*> &hash){
		if(root==NULL)
			return NULL;
		TreeNode* cloneNode = new TreeNode(root->val);
		hash[root] = cloneNode;
		cloneNode->left = copyLeftRightTree(root->left,hash);
		cloneNode->right = copyLeftRightTree(root->right,hash);
		return cloneNode;
	}


	TreeNode* cloneTree(TreeNode* root){
		if(root==NULL)
			return NULL;
		map<TreeNode*,TreeNode*> hash;
		TreeNode* newTree = copyLeftRightTree(root,hash);
		copyRandomPointer(root,newTree,hash);
		return newTree;
	}
}