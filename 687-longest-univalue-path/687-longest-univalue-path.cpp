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
        if(root==NULL)return 0;
       else helper(root);
        return ans ;
    }
    int helper(TreeNode* root){
        int left=0,right=0;
        if(root->left){
            if(root->left->val==root->val)
                left=1+helper(root->left);
            else
                ans=max(ans,helper(root->left));
        }
        if(root->right){
            if(root->right->val==root->val)
                right=1+helper(root->right);
            else
                ans=max(ans,helper(root->right));
        }
        ans=max({ans,left+right});
        return max(left,right);
    }
    
};
   
        
      
        
      