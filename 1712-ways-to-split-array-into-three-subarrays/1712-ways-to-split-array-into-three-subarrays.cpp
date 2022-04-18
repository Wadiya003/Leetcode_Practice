class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        long long ans=0,m=1e9+7;
         int leftsum, rem, midstart, midend, maxsummid, len, n = nums.size();
        vector<int>sum(n, 0);
        
        sum[0] = nums[0];
        for(int i = 1; i < n; i++) 
            sum [i] = sum[i-1] + nums[i];
        
        for(int i = 0; i < n; i++) {
            leftsum = sum[i];
            rem = sum[n-1] - leftsum;
            maxsummid = rem/2; 
            midstart = lower_bound(sum.begin() + i + 1, sum.end(), sum[i] + leftsum) -                         sum.begin();
            midend = upper_bound(sum.begin() + i + 1, sum.begin() + n - 1  , sum[i] + maxsummid) -             sum.begin();midend--;
            len = (midend - midstart + 1);
            ans += max(0, len);
        }
        
        return ans % m;
    }
};