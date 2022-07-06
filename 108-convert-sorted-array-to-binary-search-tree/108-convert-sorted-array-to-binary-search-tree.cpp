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
    TreeNode* usebinarysearch(vector<int>& nums, int start , int end){
      
        if(end<=start) return NULL; 
        int mid=(start+(end-start)/2);
        TreeNode* newnode=new TreeNode(nums[mid]);
        newnode->left=usebinarysearch(nums, start , mid);
        newnode->right=usebinarysearch(nums, mid+1 , end);
        return newnode;
        
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n =nums.size();
        return usebinarysearch(nums, 0, n);
    }
};