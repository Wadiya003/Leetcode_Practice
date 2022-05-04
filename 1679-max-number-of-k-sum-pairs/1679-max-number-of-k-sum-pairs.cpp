class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int l =0,r=nums.size()-1;
        while(l<r && nums[l]<k){
         
            if (nums[l] + nums[r] < k) {
                l++;
            } else if (nums[l] + nums[r] > k) {
                r--;
            } else {
                l++;
                r--;
                ans++;
            }
            
        }
        
        return ans;
    }
};