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
    void inorder(TreeNode* root, vector<int>& nums){
        if(root == NULL)return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>val;
        inorder(root,val);
        //sorted vector we got 
        //mnow use 2 pointer approach
        for(int i=0,j=val.size()-1;i<j;){
            if(val[i]+val[j]==k)return true;
            (val[i]+val[j]<k)?i++:j--;
        }
        return false;
    }
    
};
 