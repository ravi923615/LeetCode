class Solution{
public:
	/* Logic:
	1. Print the left boundary in top-down manner
	2. Print all leaf node from left to right, which again be sub-divided
	into two sub parts.
		2.1 Print all leaf nodes of left subtree from left to right.
		2.2 Print all leag nodes of right subtree left to right.
	3. Print the right boundary in bottom-up manner. */

	void printBoundary(TreeNode* root){
		if(root){
			cout<<root->data<<" ";

			//Print all left boundary in top down manner.
			printBoundaryLeft(root->left);

			//Print all leaf node
			printLeaves(root->left);
			printLeaves(root->right);

			//Print all right boundary nodes in bottom up manner.
			printBoundaryRight(root->right);
		}
	}

	void printLeaves(TreeNode* root){
		if(root){
			printLeaves(root->left);

			if(!root->left && !root->right)
				cout<<root->data<<" ";

			printLeaves(root->right);
		}
	}

	void printBoundaryLeft(TreeNode* root){
		if(root){
			if(root->left){

				//to ensure top down order, print the node
				// before calling itself for left subtree
				cout<<root->data<<" ";
				printBoundaryLeft(root->left);
			}
			else if(root->right){
				cout<<root->data<<" ";
				printBoundaryLeft(root->right);
			}
		}
	}

	void printBoundaryRight(TreeNode* root){
		if(root){
			if(root->right){
				cout<<root->data<<" ";
				printBoundaryRight(root->right);
			}
			else if(root->left){
				cout<<root->data<<" ";
				printBoundaryRight(root->left);
			}
		}
	}
}