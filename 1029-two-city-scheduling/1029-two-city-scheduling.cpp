class Solution {
public://can be done recursively //better is greedy 
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans=0;
        vector<int>diff;
        for(int i=0;i<costs.size();i++){
         ans+=costs[i][0];
         diff.push_back(costs[i][1]-costs[i][0]);
      }
        sort(diff.begin(),diff.end());
        for(int i=0;i<diff.size()/2;i++){
        ans+=diff[i];
        }return ans;
    }
};