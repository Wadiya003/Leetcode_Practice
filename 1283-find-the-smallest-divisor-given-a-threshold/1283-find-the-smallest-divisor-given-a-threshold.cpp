class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
         int l= 1, r= 1e6;
        while (l < r) {
            int m = l+(r-l)/2;
            int sum = 0;
            for (int n : nums)
                sum += (n + m - 1) / m;
            //if sum is greater than threshold , then increase divisor
            if (sum > threshold)
                l = m + 1;
            else //decrease
                r = m;
        }
        return l;
    }
};