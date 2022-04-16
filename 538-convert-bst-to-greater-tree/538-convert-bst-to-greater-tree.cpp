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
    int sum=0;
    void change(TreeNode* node){
     if(!node)return;
    change(node->right);
     sum += node->val;
     node->val = sum;
     change(node->left);
    }
    TreeNode* convertBST(TreeNode* root) {
   
        change(root);
        return root;
    }
};