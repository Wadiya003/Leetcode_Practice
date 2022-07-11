class Solution {
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        vector<int> dp(n+1,0);
        dp[n-1]=nums[n-1];
        dp[n-2]=max(nums[n-2],nums[n-1]);
        for(int i=n-3;i>=0;i--){
            dp[i]=max(dp[i+2]+nums[i],dp[i+1]);
        }
        return dp[0]; 
    }
};