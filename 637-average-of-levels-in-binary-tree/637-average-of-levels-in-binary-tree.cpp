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
     void avg(TreeNode* root, vector<int>& cnt, vector<double>& sum, int l) {
        if (!root) {
            return;
        }
        if (cnt.size() <= l) {
            cnt.push_back({});
        }
        if (sum.size() <= l) {
            sum.push_back({});
        }
        cnt[l]++;
        sum[l] += root -> val;
        avg(root -> left, cnt, sum, l + 1);
        avg(root -> right, cnt, sum, l + 1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> cnt;//cnt of each level
        vector<double> avgs;//avg of each level
        avg(root, cnt, avgs, 0);
        for (int i = 0; i < avgs.size(); i++) {
            avgs[i] /= cnt[i];
        }
        return avgs;
    }
};