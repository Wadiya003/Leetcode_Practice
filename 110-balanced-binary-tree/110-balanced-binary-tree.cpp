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
public:
   int solve(TreeNode* root,bool& x)
{
    if(root==NULL)
        return 0;
    
    if(x==false)
        return 0;
    
    int l=solve(root->left,x);
    int r=solve(root->right,x);
    
    if(abs(l-r)>1)
        x=false;
    
    return 1+max(l,r);
}

bool isBalanced(TreeNode* root) {
    
    bool x=true;
    solve(root,x);
    
    return x;
}
};