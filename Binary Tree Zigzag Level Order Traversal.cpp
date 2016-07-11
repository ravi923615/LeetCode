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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> getNodeSaved;
        vector<int> out;
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        getNodeSaved.push(root);
        int lvl = 1, cur=0,lvlstill=1;
        while(!getNodeSaved.empty()){
            TreeNode* topNode = getNodeSaved.front();
            getNodeSaved.pop();
            out.push_back(topNode->val);
            lvl--;
            if(topNode->left!=NULL){
                getNodeSaved.push(topNode->left);
                cur++;
            }
            if(topNode->right!=NULL){
                getNodeSaved.push(topNode->right);
                cur++;
            }
            if(lvl==0){
                lvl = cur;
                lvlstill++;
                if(lvlstill%2==0)
                    result.push_back(out);
                else{
                    reverse(out.begin(),out.end());
                    result.push_back(out);
                }
                cur = 0;
                out.clear();
            }
           
        }
        return result;
    }
};