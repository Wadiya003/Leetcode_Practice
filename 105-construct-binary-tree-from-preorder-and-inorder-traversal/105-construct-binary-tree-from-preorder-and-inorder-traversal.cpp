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
    
    TreeNode* recursion(vector<int>&preorder, vector<int>& inorder, unordered_map<int,int>&m, int ind , int i , int j ){
        if(i>j || ind>preorder.size())return NULL;
        TreeNode * temp=new TreeNode(preorder[ind]);
        int find=m[temp->val];
        temp->left=recursion(preorder,inorder,m,ind+1,i,find-1);
        temp->right=recursion(preorder,inorder,m,ind+find-i+1,find+1,j);
        return temp;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     //map to store position of element of inorder in preorder 
        unordered_map<int,int>m;
        for(int a =0;a<preorder.size();a++){
          m[inorder[a]]=a;
        }
        int preindex=0;
        return recursion(preorder,inorder,m,preindex,0,preorder.size()-1);
    }
};