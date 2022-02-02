class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>&nums, int i ){
        if(i>=nums.size()){
        res.push_back(nums);
        }
        else
            for (int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            helper(nums, i+1);
            swap(nums[i],nums[j]);
            }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
     helper(nums,0);
     return res;
    }
		
};