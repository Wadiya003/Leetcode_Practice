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
    int maxLevelSum(TreeNode* root) {
       unordered_map<int,int>m;
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        // vector<vector<int>>ans;
        vector<int>v;
        while(!q.empty()){
            int sz=q.size();
            for(int i =0;i<sz;i++){
                TreeNode* t=q.front();
                q.pop();
                v.push_back(t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            int sum=accumulate(v.begin(),v.end(),0);
            m[level++]=sum;
            v.clear();
        }
        int ans=0;
        int pre=INT_MIN;
        for(auto a:m){
        if(a.second>=pre){
            pre=a.second;
            ans=a.first;
        }
        }
        return ans ;
         
    }
};