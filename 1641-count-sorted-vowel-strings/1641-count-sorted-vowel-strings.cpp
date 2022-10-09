class Solution {
public:
    int helper(int n,int i,vector<vector<int>>&dp ){
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        int ans=0;
        for(int vow=i;vow<5;vow++){
            ans+=helper(n-1,vow,dp);
        }
        return dp[n][i]=ans;
    }
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        return helper(n,0,dp);
    }
};