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
    TreeNode* change1=NULL;
    TreeNode* change2=NULL;
    TreeNode* temp=new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
       inorder(root);
       swap(change1->val,change2->val);
        
    }
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        //check and assign val
        if(change1==NULL && temp->val>root->val){
        change1=temp;
        }
        if(change1!=NULL && temp->val>root->val){
        change2=root;
        }
        temp=root;
        inorder(root->right);
        
        
}
};