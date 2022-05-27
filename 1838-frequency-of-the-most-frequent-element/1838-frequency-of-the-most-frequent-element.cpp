class Solution {
public:
    #define ll long long
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=0;
        ll totsum=0;
        int ans=0;
        while(r<nums.size()){
           totsum+=nums[r];
               while((1ll)*(r - l + 1)*nums[r] - totsum > k){
                totsum -= nums[l];
                l++;
            }
            ans=max(ans,r-l+1);  
            r++;
        }
        return ans;
    }
};
/*
sort and sliding window
 

*/