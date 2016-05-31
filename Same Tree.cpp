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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p&&q){
           if(p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
            return 1;
            else
                return 0;
       }
       if(p||q)
        return 0;
      return 1;
    }
};