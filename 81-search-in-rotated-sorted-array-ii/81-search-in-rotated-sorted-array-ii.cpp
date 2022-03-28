class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0){
        return false;}
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            while (l < r && nums[l] == nums[l + 1])
        ++l;
            while (l < r && nums[r] == nums[r - 1])
        --r;
         int m=l+(r-l)/2;
         if(nums[m]==target){
          return true;
         }  
         else if(nums[m]>=nums[l]){
         if(target>=nums[l] && target<nums[m])
         r=m-1;  //left sorted arr
         else l=m+1;
         } //right sorted arr   
         else{
         if(target<=nums[r] && target>nums[m])
         l=m+1;
         else r=m-1;
         }
         }
         return false;
        
    }
};