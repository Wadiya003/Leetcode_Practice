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
    //bfs
    int goodNodes(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*, int>>q;
        q.push({root,INT_MIN});
        while(!q.empty()){
        pair<TreeNode*,int>p=q.front();
        q.pop();
        TreeNode* t=p.first;
        int maxx=p.second;
        if(t->val>=maxx){
            ans++;
        }
        if(t->left){
            q.push({t->left,max(maxx,t->val)});
        }
        if(t->right){
            q.push({t->right,max(maxx,t->val)});
        }
        }
        return ans;
    }
};




