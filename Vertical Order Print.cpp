class Solution{
public:
	/* Q: Given a binary tree, print it vertically.
	Sol: An efficient solution is based on hashmap. We need to check the horizontal
	distances(HD), then they are on same vertical line. The idea of HD is simple,
	HD for root is 0, a right edge(edge connecting to right substree) is considered
	as +1 horizontal distance and left edge is considered as -1 horizontal distance.

	We can do inorder traversal of the given binary tree. while traversing 
	the tree, we can recursively calculate HDs. We initially pass the horizontal
	distance as 0 for root. For left subtree, we pass HD as HD of root minus 1.
	For right subtree, we pass the HD as HD of root plus 1. For every HD value 
	we maintain a list of nodes in hashmap. whenever we see a node in traversal
	we go to the hash map entry and add the node to the hash map using HD as key
	in map. */
struct TreeNode
{
	int key;
	TreeNode* left,right;
	TreeNode(int key): key(x),left(NULL),right(NULL){}
};

void getVerticalOrder(TreeNode* root, int hd, map<int,vector<int>> &m){
	//Base case
	if(root==NULL)
		return;
	m[hd].push_back(root->key);

	//Store nodes in left subtree
	getVerticalOrder(root->left,hd-1,m);

	//Store nodes in right subtree
	getVerticalOrder(root->right,hd+1,m);
}

void printVerticalOrder(TreeNode* root){
	//Create a map and store vertical order in map
	//using function getVerticalOrder().
	map<int,vector<int>> m;
	int hd = 0;
	getVerticalOrder(root,hd,m);

	for(std::map<int,vector<int>>::iterator it=m.begin();it!=m.end();++it){
		for(int i=0;i<it->second.size();i++){
			cout<<it->second[i]<<" ";
		cout<<endl;
		}
	}
}

}