class Solution {
public://Eg :4=> less than 4 would be 4
    int findDuplicate(vector<int>& nums) {
        int n =nums.size();
        int l=1;
        int r=nums.size()-1;
        while(l<=r){
       int m=l+(r-l)/2;
       int cnt = 0;
            //search for smaller numbers than mid
            for(auto num : nums) if(num <= m) cnt++;
            //if smaller numbers cnt is less than or equal to mid ,that means duplicate is in right side ,therfore discard left search space
            if(cnt <= m) l = m+1;
            //else verdict is in left search space
            else r = m-1;
       
        }
        return l;
        
    }
    // bool isokay(vector<int>&nums,int m){
    //     int tot=0;
    //     for(int i=0;i<nums.size();i++){
    //      if(nums[i]<=m)tot++;
    //     }
    //     return tot==m;
    // }
};