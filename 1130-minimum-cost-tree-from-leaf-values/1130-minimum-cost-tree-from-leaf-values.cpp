class Solution {
public: //IDEA->DP(MEMOIZATION)
//     1)l=0;h=n-1;
//     make left subtree from  l to i ;
//     make right subtree from i+1 to h;
//     take max ;
    
    int mctFromLeafValues(vector<int>& arr) {
        int  h =arr.size();
        vector<vector<int>> dp(h+1, vector<int>(h+1,-1));
        return helper(0,h-1,arr, dp);
    }
    int helper (int l , int h , vector<int>&arr , vector<vector<int>> &dp){
       //BASE CASES
        if(l==h)return dp[l][h]=0;
        if(h-l==1)return dp[l][h]=arr[h]*arr[l];
        if (dp[l][h]!=-1)return dp[l][h];
        int ans=INT_MAX;
        for(int i =l;i<h ;i++){
            int left =highest(l,i,arr);
            int right=highest(i+1,h,arr);
            int add =helper(l,i,arr,dp)+helper(i+1,h,arr,dp);
            ans =min(ans,(left*right)+add);
        }
        return dp[l][h]=ans;
    }
    int highest(int l , int h , vector<int>&arr){
        int maxelement =0;
        for(int i =l;i<= h;i++){
        maxelement=max(maxelement, arr[i]);
        }
        return maxelement ;
    }
    
 
};
