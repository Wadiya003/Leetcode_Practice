class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int sum =0,p,x;
     
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];

        }
        p = nums.size()*(nums.size() + 1)/2;
        x = p - sum;
        
        return x;
    }
};