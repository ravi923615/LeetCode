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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> qu;
        qu.push(root);
        vector<int> out;
        int level=1;
        int cnter = 0;
        while(!qu.empty()){
           TreeNode* front = qu.front();
           qu.pop();
           if(level!=0){
               out.push_back(front->val);
               level--;
           }
           if(front->left!=NULL){
               qu.push(front->left);
               cnter++;
           }
           if(front->right!=NULL){
               qu.push(front->right);
               cnter++;
           }
           if(level==0){
               res.push_back(out);
               level = cnter;
               cnter = 0;
               out.clear();
           }
        }
        return res;
    }
};