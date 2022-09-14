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
    int ans=0;
    int pseudoPalindromicPaths (TreeNode* root) {
        set<int>s;
        dfs(root,s);
        return ans;
    }
    void dfs(TreeNode* root,set<int>s){
        if(root==NULL)return;
        if(s.find(root->val)!=s.end()){
            s.erase(root->val);
        }
        else{
            s.insert(root->val);
        }
        if(!root->left && !root->right){
            if(s.size()<=1)ans++;
        }
        if(root->left)dfs(root->left,s);
        if(root->right)dfs(root->right,s);
    }
};