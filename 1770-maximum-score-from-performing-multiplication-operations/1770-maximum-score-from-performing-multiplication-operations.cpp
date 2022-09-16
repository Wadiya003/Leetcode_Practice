class Solution {
public:    
    //iterative dp
   
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int dp[1001];
        memset(dp,0,sizeof(dp));
        for(int i=multipliers.size()-1;i>=0;i--){
            for(int start=0;start<=i;start++){
               int end=nums.size()-1-(i-start);
               int l=multipliers[i]*nums[start]+dp[start+1];
               int r=multipliers[i]*nums[end]+dp[start];
               dp[start]=max(l,r);
            }
        }
        return dp[0];
    }
    
};
//3 2 1
//1 2 3