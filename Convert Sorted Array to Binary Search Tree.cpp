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

    TreeNode* newNode(int data){
        TreeNode* root= (TreeNode*)malloc(sizeof(TreeNode));
        root->val = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    TreeNode* getTreeDone(vector<int> &nums,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid;
        if((start+end)%2!=0)
            mid = ((start+end)/2)  + 1;
        else
            mid = (start+end)/2;
        TreeNode* root = newNode(nums[mid]);
        root->left = getTreeDone(nums,start,mid-1);
        root->right = getTreeDone(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        TreeNode* root = NULL;
        root = getTreeDone(nums,0,nums.size()-1);
        return root;
        
    }
};