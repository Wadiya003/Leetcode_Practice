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
    TreeNode* recoverFromPreorder(string traversal) {
        
        unordered_map<int, TreeNode*>mp;        
        for(int i = 0; i < traversal.length(); i++)
        {
             string val="";
            int dashes=0;
            while( i<traversal.length() && traversal[i]=='-')
            {
                dashes++;
                i++;
            }
            while(i<traversal.length() && traversal[i]!='-')
                val+=traversal[i++];
            int num=stoi(val);
            TreeNode * newnode =new TreeNode(num); 
            mp[dashes] = newnode;//Saving the node with depth
            
            if(mp.find(dashes - 1) != mp.end())
            {                
                TreeNode *parent = mp[dashes- 1];
                if(parent -> left == NULL)
                    parent -> left = newnode;
                else
                    parent -> right = newnode;
            }//Finding parent and linking the child
            i--;
        }
        return mp[0];
    }
//          stack<pair<TreeNode *,int>> st;
        
//         int i=0;
//         int n=traversal.size();
//         while(i<n)
//         {
//             string val="";
//             int dashes=0;
//             while( i<n && traversal[i]=='-')
//             {
//                 dashes++;
//                 i++;
//             }
//             while(i<n && traversal[i]!='-')
//                 val+=traversal[i++];
//             int num=stoi(val);
//             TreeNode * newNode =new TreeNode(num); 
//             if(st.empty())
//             {
//                 st.push({newNode,dashes});                
//             }
//             else
//             {
//                 while(!st.empty() && st.top().second>=dashes)
//                     st.pop();
                
//                 if(st.top().first->left==NULL)
//                     st.top().first->left=newNode;
//                 else 
//                     st.top().first->right=newNode;
                
//                 st.push({newNode,dashes});
                    
//             }
                
//         }
//         while(st.size()!=1)
//             st.pop();
//         return st.top().first;
//     }

};

           
    
      