class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        int upwigg=1,downwigg=1;
        for(int i =1; i<nums.size();i++){
            if(nums[i]>nums[i-1]){
            upwigg=downwigg+1;}
            
            else if(nums[i]<nums[i-1]){
                downwigg=upwigg+1;
            }
        }return max(upwigg,downwigg);
    }
};