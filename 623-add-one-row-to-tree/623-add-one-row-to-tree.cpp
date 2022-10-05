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
    void helper(TreeNode* root, int val, int depth, int d){
    if(root==NULL){
    return; }
    if(d==depth-1){
        TreeNode *let=root->left;
        root->left=new TreeNode(val);
        root->left->left=let;
        TreeNode *tel=root->right;
        root->right=new TreeNode(val);
        root->right->right=tel;

    }
    else{
         helper(root->left,val,depth,d+1);
         helper(root->right,val,depth,d+1);
    }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL)
            return nullptr;
        if(depth==1){
            TreeNode *n=new TreeNode(val);
            n->left=root;
            return n;
        }
        helper(root,val,depth,1);
        return root;
        
    }
};