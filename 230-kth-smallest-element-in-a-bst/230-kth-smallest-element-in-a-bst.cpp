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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        while(true){
          while(root!=NULL){
           s.push(root);
          root=root->left;
          }
            TreeNode* t = s.top();
            s.pop();
            k--;
            if(k == 0)
                return t->val;
            root = t->right;
        }return -1;
    }
};