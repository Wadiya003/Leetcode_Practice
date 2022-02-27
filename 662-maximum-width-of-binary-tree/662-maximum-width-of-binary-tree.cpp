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
public://BFS
    
    int widthOfBinaryTree(TreeNode* root) {
      if(root==NULL)return 0;
        int ans=0;
      queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
          int size=q.size(); //1
            int leftmost=q.front().second;//0
            int rightmost=q.back().second;//0
            ans =max(ans,rightmost-leftmost+1);//1
            for(int i =0;i<size;i++){
                TreeNode* temp=q.front().first;//root==1
                long long idx=q.front().second-leftmost;//0
                q.pop();
                if(temp->left)
                        q.push({temp->left,2*idx});//3,0
                
                if(temp->right)
                        q.push({temp->right,2*idx+1});//2,1
                
            }
        }return ans;
            
    }
};
