class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
         if (n == 0)
        return 0;
        vector<int>sums(n+1,0);
        if(nums.size()==0){
            return 0;
        }
        for(int i=1;i<=nums.size();i++){
         sums[i]=sums[i-1]+nums[i-1];
        }
        for(int i=1;i <= nums.size();i++){
            int find=target+sums[i-1];
            auto bound =lower_bound(sums.begin(),sums.end(),find);
            if(bound!=sums.end()){
                ans=min(ans,static_cast<int>(bound-(sums.begin()+i-1)));
            }
        }
        return (ans!=INT_MAX)?ans:0;
    }
};