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
    int maxDepth(TreeNode* root) {
        
        int lght,rght;
        
        if(!root)
            return 0;
        lght = maxDepth(root->left);
        rght = maxDepth(root->right);
        
        return max(lght,rght)+1;
        
    }
};