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
    //backtrack 
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > ans;
        vector<int> temp;
        backtrack(root, targetSum, temp, ans);
        return ans;  
    }
    void backtrack(TreeNode* root, int sum, vector<int>&temp, vector<vector<int>>&ans){
        if(root==NULL)return;
        temp.push_back(root->val);
        if(!root->left && !root->right && root->val==sum)ans.push_back(temp);
        backtrack(root->left,sum-root->val,temp,ans);
        backtrack(root->right,sum-root->val,temp,ans);
        temp.pop_back();
    }
};
  
       