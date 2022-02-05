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
public://Recursion
    vector<TreeNode*> generateTrees(int n) {
        return make(1,n);
    }
    vector<TreeNode*> make(int l,int r){
    if ( l > r)return {NULL};
    if(l==r)return {new TreeNode(l)};
        vector<TreeNode*> ans;
    for(int i =l;i<=r;i++){
        vector<TreeNode*> left= make(l,i-1);
        vector<TreeNode*> right =make(i+1,r);
            for ( auto j : left){
               for ( auto k: right){
                TreeNode* root=new TreeNode(i);
                   root->left=j;
                   root->right=k;
                   ans.push_back(root);
           }
        }
    }
    return ans ;}
    
    
};