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
    enum camera{
        HasCam=1,
        NoCam=0,
        Covered=-1
};
    int ans=0;
    int minCamera(TreeNode* root){
        if(!root)return Covered;
        int l= minCamera(root->left);
        int r= minCamera(root->right);
        if ( l==NoCam || r==NoCam){
        ++ans;
        return HasCam;
        }
        if(l==HasCam || r==HasCam){
        return Covered;}
        else{
        return NoCam;
        }
        return ans;    
}
    int minCameraCover(TreeNode* root) {
        if(minCamera(root)==NoCam)++ans;
        return ans;
    }
};