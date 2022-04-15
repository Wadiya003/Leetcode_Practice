class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        
       long m=1000000007, tot = 0, gain = 0;
        vector<int>s=nums1;
        sort(s.begin(),s.end());
    for (int i = 0; i < nums1.size(); ++i) {
        long sum = abs(nums1[i] - nums2[i]);
       tot += sum;
        if (gain < sum) {
            auto it = lower_bound(s.begin(), s.end(), nums2[i]);
            if (it != end(s))
                gain = max(gain, sum - abs(*it - nums2[i]));
            if (it != begin(s))
                gain = max(gain,sum - abs(*prev(it) - nums2[i]));//catch
        }
    }
    return (tot - gain) % m;
    }
};
