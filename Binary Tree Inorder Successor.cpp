class Solution{
public:
	// 1) If right subtree of node is not NULL, then succ lies in right subtree.
	// Do following Go to right substree and return Node with minimum key value
	// in right subtree.

	// 2) If right subtree of node is NULL, then succ is one of the ancestors. Do following
	// Travel up using the parent pointer until you see a node which is left
	// chile of its parent. The parent of such node is the succ.
	struct TreeNode
	{
		int data;
		struct TreeNode* left;
		struct TreeNode* right;
		struct TreeNode* parent;
	};
	

	TreeNode* minValue(TreeNode* node){
		TreeNode* cur = node;
		while(cur->left){
			cur = cur->left;
		}
		return cur;
	}

	TreeNode* getInorderSuccessor(TreeNode* node){
		//step 1 of the above algorithm
		if(node->right!=NULL)
			return minValue(n->right);

		//step 2 of the above algorithm
		TreeNode* p = n->parent;
		while(p!=NULL && n == p->right){
			n = p;
			p = p->parent;
		}
		return p;
	}
}