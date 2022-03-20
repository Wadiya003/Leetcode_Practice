class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        if (n <= 2)
            return 0;

        for (int i = 1; i <n - 1; i++)
        {   
            int pre = i - 1;
            int post =i + 1;
            if(nums[i] == nums[i-1]) continue; 
             while(pre >= 0 && nums[pre] == nums[i]) pre--;
             if(pre< 0) continue;
			
            while(post < n && nums[post] == nums[i]) post++;
            if(post == n) continue; 
            if (nums[i] > nums[pre] && nums[i] > nums[post] || nums[i] < nums[pre] && nums[i] < nums[post]){ 
                // To see if it is a peak or a valley
                cnt++;
        }
          
        }
        return cnt;
    }
};