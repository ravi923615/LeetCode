class Solution{
public:
	/*Q: Print the Nodes in top view of Binary Tree. */
	void topViewBinaryTree(TreeNode* root){
		//Logic is use vertical order traversal. Or use level order 
		//traversal and calculate the horizontal distance.
		queue<TreeNode*> lvlOrder;
		queue<int> HDQ;
		int HD = 0;
		lvlOrder.push(root);
		HDQ.push(0);
		map<int,int> hash;
		while(!lvlOrder.empty()){
			TreeNode* tmp = lvlOrder.front();
			lvlOrder.pop();
			HD = HDQ.front();
			HDQ.pop();
			if(hash.find(HD)==hash.end()){
				hash[tmp->val]++;
			}
			if(tmp->left){
				int tHD = HD-1;
				HDQ.push(tHD);
				lvlOrder.push(tmp->left);
				curlvl++;
			}
			if(tmp->right){
				int trHD = HD+1;
				HDQ.push(trHD);
				lvlOrder.push(tmp->right);
				curlvl++;
			}
		}
		for(map<int,int>::iterator it=hash.begin();it!=hash.end();++it){
			cout<<it->first()<<endl;
		}
	}

}