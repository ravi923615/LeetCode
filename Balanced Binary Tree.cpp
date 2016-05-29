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
    bool isBalanced(TreeNode* root) {
        return findDepth(root)==-1?false:true;
    }
    
    int findDepth(TreeNode* root){
        if(!root) return 0;
        
        int lght = findDepth(root->left);
        if(lght==-1)return -1;
        int rght = findDepth(root->right);
        if(rght==-1)return -1;
        
        if(abs(lght-rght)>1)
            return -1;
        return max(lght,rght)+1;
    }
};