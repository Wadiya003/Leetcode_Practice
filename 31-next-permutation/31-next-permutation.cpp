class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
        int inc = -1, till = -1;
        for(int i = 0; i < n-1; i++) 
            if(nums[i] < nums[i+1]) 
                inc = i;
        if(inc == -1)
        {
            sort(nums.begin(), nums.end());
            return ;
        }
        for(int i = inc+1; i < n; i++) 
            if(nums[inc] < nums[i]) 
                till = i;
         swap(nums[inc], nums[till]);
         reverse(nums.begin()+inc+1, nums.end());
    }
};