class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int ans=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                ans=mid;
                return ans;
            }
            else if(nums[mid]<target){
             start=mid+1;
            }
            else{
              end=mid-1;
            }
        }return -1;
    }
};