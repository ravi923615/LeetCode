class Solution{
public:
	/* LOGIC: Do a traversal of the given tree. In traversal, store the old
	value of current node, recusively call for left and right subtrees and 
	change the value of current node as sum of the values return by recursive 
	calls. Finally return the sum of new value and value(which is sum
	of values in subtree rooted with this node). */

	int toSumTree(TreeNode* root){
		if(root==NULL)
			return 0;

		int old_val = root->val;
		
		root->data = toSumTree(root->left) + toSumTree(root->right);

		return root->data+old_val;
	}
}