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
    bool check(TreeNode* a, TreeNode* b){
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    if (a->val != b->val) return false;
    return true;  
   }
    bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (!check(p, q)) return false;
        queue<pair<TreeNode*,TreeNode*>>qq;
        qq.push({p,q});
        while(!qq.empty()){
        pair<TreeNode*,TreeNode*> pp= qq.front();
        qq.pop();
        if(!check(pp.first, pp.second)) return false;
      
            if (pp.first->right == NULL || pp.second->right == NULL) {
                if (pp.first->right != NULL || pp.second->right !=NULL) 
                    return false;
            } else {
              qq.push({pp.first->right,pp.second->right});
            }
        if(!check(pp.first, pp.second)) return false;
      
            if (pp.first->left ==NULL || pp.second->left  == NULL) {
                if (pp.first->left  != NULL|| pp.second->left  !=NULL) 
                    return false;
            } else {
              qq.push({pp.first->left ,pp.second->left });
            }
          
        }
        return qq.empty();
    }
};