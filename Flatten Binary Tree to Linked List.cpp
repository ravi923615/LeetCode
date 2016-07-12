/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getPreOrder(TreeNode* root,vector<int> & val){
        if(root==NULL)
            return;
        val.push_back(root->val);
        getPreOrder(root->left,val);
        getPreOrder(root->right,val);
    }
    void setLinkedList(TreeNode* root,int i,vector<int> val){
        if(i>=val.size())
            return;
        TreeNode* tmp = new TreeNode(val[i]);
        tmp->right = NULL;
        tmp->left = NULL;
        root->right = tmp;
        setLinkedList(root->right,i+1,val);
    }
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        vector<int> val;
        getPreOrder(root,val);
        root->left = NULL;
        root->right = NULL;
        setLinkedList(root,1,val);
    }
};