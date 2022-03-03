class Solution {
public://pattern
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        int count=1;
        int ans=0;
        for(int i =2;i<nums.size();i++){
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
        ans+=count++;
        }
        else count=1;}
        return ans;
        
    }
};