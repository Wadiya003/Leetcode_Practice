class Solution {
public:
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
      vector<int>ans;
    vector<vector<int>>res;
      sort(candidates.begin(),candidates.end());
      helper(candidates,target,0,ans,res);
      
      return res;
    }
    
  
    
    void helper(vector<int>& nums , int target , int start,vector<int>& ans,vector<vector<int>>&res ){
    int n =nums.size();
        if(target==0){res.push_back(ans);
            return;}
        
        for(int i=start;i<n;i++){
             if(nums[i] > target) break;
            if(i>start&& nums[i]==nums[i-1])continue; //duplicates handling
            ans.push_back(nums[i]);
            helper(nums, target-nums[i],i+1,ans,res);
            ans.pop_back();
        }
    }

        
   
};
