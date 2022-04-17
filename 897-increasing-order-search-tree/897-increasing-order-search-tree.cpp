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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)return NULL;
        TreeNode* left=increasingBST(root->left);
        TreeNode* right=increasingBST(root->right);
        root->left=nullptr;
        root->right=right;
        if(left==NULL)return root;
        TreeNode* it = left;
        while (it && it->right) {
            it = it->right;
        }
        it->right = root;
        return left;
    }
};