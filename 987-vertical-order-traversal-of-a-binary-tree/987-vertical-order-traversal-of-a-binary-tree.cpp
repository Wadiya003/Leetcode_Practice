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
           vector<vector<int>>ans; 
        if(root == NULL)
        return ans;
        
        queue<pair<TreeNode*,int>>qu;//val and col
        qu.push({root,0});
        int row=0;
        map<int,vector<pair<int,int>>> m; //col,val and row
		
		//bfs traversal
        while(!qu.empty())
        {
            int size = qu.size();
            while(size--){
                TreeNode* temp = qu.front().first;
                int col = qu.front().second;
                qu.pop();
                m[col].push_back({temp->val,row});
                if(temp->left)
                qu.push({temp->left,col-1});
                if(temp->right)
                qu.push({temp->right,col+1});
            }
            row++; 
        }
        
		
		//putting values in vector
        vector<pair<int,int>> v;
        for(auto it=m.begin();it!=m.end();it++){
            v=it->second;//val and row
            sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b)
            {
               if(a.second==b.second)  //if same row then take less val
                   return a.first<b.first;
               else 
                   return a.second<b.second;//else smaller row 
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