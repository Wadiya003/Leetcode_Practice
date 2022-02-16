class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        helper(nums, v, 0);
        return v;
        
    }
    void helper(vector<int> nums,vector<vector<int>>&v,int ind){
        vector<int>ans;
        if(ind==nums.size()){
            v.push_back(nums);
        }
        for(int i=ind;i<nums.size();i++){
            if(i!=ind&&nums[i]==nums[ind]){continue;}
            swap(nums[i], nums[ind]);
            helper(nums, v, ind + 1);
        }
    }
};