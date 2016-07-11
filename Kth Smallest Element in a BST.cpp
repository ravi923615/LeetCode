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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> savenode;
        vector<int> numbers;
        TreeNode* cur = root;
        while(!savenode.empty() || cur){
            if(cur){
                savenode.push(cur);
                cur = cur->left;
            }else{
                TreeNode* tmp = savenode.top();
                numbers.push_back(tmp->val);
                cur = tmp->right;
                savenode.pop();
            }
        }
        return numbers[k-1];
    }
};