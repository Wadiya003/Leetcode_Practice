class Solution {
public:    
    //iterative dp
   
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int dp[1001][1001];
        memset(dp,0,sizeof(dp));
        for(int i=multipliers.size()-1;i>=0;i--){
            for(int start=i;start>=0;start--){
               dp[i][start]= max(multipliers[i]*nums[start]+dp[i+1][start+1],multipliers[i]*nums[nums.size()-(i-start)-1]+dp[i+1][start]);
            }
        }
        return dp[0][0];
    }
    
};
//3 2 1
//1 2 3