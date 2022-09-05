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
     
     void dfs(TreeNode* node, int maxx){
         if(node==NULL){
             return ;
         }
         if(node->val>=maxx){
             cnt++;
             maxx=node->val;
         }
         dfs(node->left,maxx);
         dfs(node->right,maxx);
         
     }
public:
    //dfs 
    //store count and keep changing max value
    int cnt=0;
    int goodNodes(TreeNode* root) {
      dfs(root,root->val);
      return cnt;
    }
   
};