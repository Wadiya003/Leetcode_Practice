class Solution {
public: //knapsack 
     bool helper(int i, int sum, vector<int> &nums, int totalSum, int dp[]) {
        if (dp[sum] != -1) {
            return dp[sum];
        }
        
        if (i== nums.size()) {
            return (sum == (totalSum - sum));
        }
        
        // Take current value
        bool A = helper(i + 1, sum + nums[i], nums, totalSum, dp);
        
        // Don't take current value
        bool B = helper(i + 1, sum, nums, totalSum, dp);
        
        dp[sum] = A || B;
        return dp[sum];
    }
    bool canPartition(vector<int>& nums) {
    int dp[20001];
        memset(dp, -1, sizeof(dp));
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        return helper(0, 0, nums, totalSum, dp);
    }
};