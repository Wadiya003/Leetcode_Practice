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
public://dfs 
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL)return 0;
        stack <pair<TreeNode*,int>> st;
        st.push({root,0});
        int sum=0;
        while(!st.empty()){
            auto cur=st.top();
            st.pop();
            TreeNode* temp=cur.first;
            int ans=cur.second;
             ans =ans*2 +temp->val ;
             if(!temp->left && !temp->right){
              sum+=ans;
             }if(temp->left){
            st.push({temp->left,ans});}
               if(temp->right){
            st.push({temp->right,ans});}      
        }return sum;
    }
};