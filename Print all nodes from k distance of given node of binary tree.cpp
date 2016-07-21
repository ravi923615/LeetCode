#include<iostream>

struct node
{
	int data;
	struct node *left,*right;
};

/* Recursive function to print all the nodes at distance k in the tree rooted
with given root */
void printKdistanceNode(node* root,int k){
	if(root==NULL && k<0) return ;

	if(k==0){
		cout<<root->data<<endl;
		return;
	}
	printKdistanceNode(root->left,k-1);
	printKdistanceNode(root->right,k-1);
}

int printKdistance(node* root,node* target,int k){
	//Base case 1:
	if(root==NULL)	return -1;

	if(root==target){
		printKdistanceNode(root,k);
		return 0;
	}

	//Recur for left subtree
	int dl = printKdistance(root->left,target,k);

	//check if target node was found in left subtree
	if(dl!=-1){
		// If root is at distance k from target, print root
		// Note that dl is Distance of root's left child from target
		if(dl+1==k)
			cout<<root->data<<endl;

		//Else go to right subtree and print all k-dl-2 distance nodes
		// Note that right child is 2 edges away from left child
		else
			printKdistanceNode(root->right,k-dl-2);

		//Add 1 to distance and return value for parent calls.

		return 1+dl;
	}

	int dr = printKdistance(root->right,target,k);
	if(dr!=-1){
		if(dr+1==k)
			cout<<root->data<<endl;
		else
			printKdistanceNode(root->left,k-dr-2);

		return 1+dr;
	}

	return -1;

}