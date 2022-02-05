/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: int ans;
  
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return ans ;
    }
    int helper(TreeNode* root){
       
   if (root==NULL)return 0;
    int left =helper(root->left);
    int right =helper(root->right);
    if(root->left && root->left->val==root->val){
        left++;}
        else left=0;
     
    if(root->right && root->right->val==root->val){
        right++;}
    else right=0;
       ans=max(ans,left+right);
        return max(left,right) ;
    
    }
};
   
        
      
        
      