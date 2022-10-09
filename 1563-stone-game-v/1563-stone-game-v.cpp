class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>& arr, int l, int r, vector<int>& prefix, vector<vector<int>>& memo){
        if(l == r){
            return 0;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int result = INT_MIN;
        for(int m=l+1; m<=r; m++){
            int leftSum = prefix[m]-prefix[l];
            int rightSum = prefix[r+1]-prefix[m];
            if(leftSum > rightSum){
                result = max(result, rightSum + helper(arr, m, r, prefix, dp));
            }
            else if(leftSum < rightSum){
                result = max(result, leftSum + helper(arr, l, m-1, prefix, dp));
            }
            else{
                result = max({ result, rightSum + helper(arr, m, r, prefix, dp), leftSum + helper(arr, l, m-1, prefix, dp) });
            }
        }
        
        return dp[l][r] = result;
    }
    
    int stoneGameV(vector<int>& stoneValue) {
     dp.resize(stoneValue.size(),vector<int>(stoneValue.size(),-1));
     vector<int>presum(stoneValue.size()+1,0);
        for(int i=0;i< stoneValue.size();i++){
           presum[i+1]=presum[i]+stoneValue[i];
        }
        return helper(stoneValue,0,stoneValue.size()-1,presum,dp);
    }
};