class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4)return false;
        int k =4;
        int n=matchsticks.size();
        vector<int>vis(16,0);
        int ksum=sum/4;
        sort(matchsticks.begin(),matchsticks.end(), greater<int>() );
        if(matchsticks[0]>ksum) return false;
        vector<int> dp(4,0);
        return dfs(matchsticks,dp,0,ksum);
    }
    bool dfs(vector<int>& matchsticks, vector<int>& dp, int ind, int s){
        if(ind==matchsticks.size())
            return dp[0]==dp[1] && dp[1]==dp[2] && dp[2]==dp[3];
         
        for(int i=0;i<4;i++)
        {
            if(dp[i]+matchsticks[ind]>s)
                continue;

             int j = i;
            while (--j >= 0) 
                if (dp[i] == dp[j]) 
                    break;
            if (j != -1) continue;
            
            dp[i]+=matchsticks[ind];
            if(dfs(matchsticks,dp,ind+1,s)) 
                return true;
            dp[i]-=matchsticks[ind];

        }
        return false;
        
    }
};