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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        if(root==NULL)
            return out;
        stack<TreeNode*> inorder;
        inorder.push(root);
        TreeNode* tmp = root->left;
        while(!inorder.empty() || tmp){
           if(tmp){
               inorder.push(tmp);
               tmp = tmp->left;
           }else{
                tmp = inorder.top();
                out.push_back(tmp->val);
                inorder.pop();
                tmp = tmp->right;
           }
        }
        return out;
    }
};