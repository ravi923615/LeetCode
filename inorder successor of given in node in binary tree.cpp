class Solution{
public:

	TreeNode* minValue(TreeNode* node){
		TreeNode* current = node;
		while(current->left!=NULL){
			current = current->left;
		}
		return current;
	}
	TreeNode* inOrderSuccessor(TreeNode* root,TreeNode* node){
		//step1: if node right is present then successor is minimum 
		// value in right subtree of the node.
		if(node->right!=NULL)
			return minValue(node->right);
		//Step2: if node right is NULL then successor is one of the ancestor
		// Travel up using parent pointer until you see the left child of its
		// parent. The parent of such a node is succ.
		TreeNode* prnt = node->parent;
		while(prnt!=NULL && node==prnt->right){
			node = p;
			prnt = prnt->parent;
		}
		return parent;
	}
	
}