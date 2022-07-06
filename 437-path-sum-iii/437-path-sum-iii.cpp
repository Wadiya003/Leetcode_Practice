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
    void dfs(TreeNode* root, int sum, long cursum, unordered_map<int,int>f){
        if(!root)return;
        cursum+=root->val;
        int findinmap=cursum-sum;
        if (f.count(findinmap)) {
            ans += f[findinmap];
        }
        f[cursum]++;
        dfs(root->left, sum,cursum,f);
        dfs(root->right, sum,cursum,f);
        f[cursum]--;
            
    }
    
    int pathSum(TreeNode* root, int targetSum) {
    int sum=targetSum;
    long cursum=0;
    unordered_map<int,int>f; 
        f[0]=1;
        dfs(root,sum,cursum,f);
        return ans;
    }
};