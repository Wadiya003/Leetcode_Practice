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
class Solution {//bfs and map pair
public://keep track of horizontal distances
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>>m;
        
        if(!root)return ans;
        queue<pair<TreeNode*,int>>q;
        int row=0;
        q.push({root,0});
        while(!q.empty()){
            int n =q.size();
            while(n--){
                TreeNode* temp =q.front().first;
                int col=q.front().second;
                q.pop();
                m[col].push_back({temp->val,row});
                if(temp->left){
                q.push({temp->left,col-1});
                }
                if(temp->right){
                 q.push({temp->right,col+1});   
                }
            }row++;
        }
        vector<pair<int,int>> v;
        for(auto it=m.begin();it!=m.end();it++){
            v=it->second;
            sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b)
            {
               if(a.second==b.second)
                   return a.first<b.first;
               else 
                   return a.second<b.second;
            });
            vector<int> v1;
            for(auto i:v){
                v1.push_back(i.first);

            }
            ans.push_back(v1);
            v1.clear();  
        }
        return ans;

        
    }
};