class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        int count=0;
       
        //*******************BINARYSEARCH******************
        vector<int>dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(dp.back()<nums[i])
            {
                dp.push_back(nums[i]);
            }
            else
            {
             auto x = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[x]=nums[i];
            }
        }
        return dp.size();
    
    }
};