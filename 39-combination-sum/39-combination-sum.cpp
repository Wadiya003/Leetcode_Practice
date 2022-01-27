class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector< int>> ans;
        vector<int> res;
        helper(candidates,0, target,ans,res);
        return ans;
    }
    void helper(vector<int>& candidates,int idx,int target, vector<vector<int>>& ans, vector<int>& res){
        
        if(idx==candidates.size()){  
            if(target==0){
                ans.push_back(res);
            }
            return;
        } 
        if(candidates[idx]<=target){  //If element<=target,we include it
         res.push_back(candidates[idx]);
            helper(candidates,idx,target-candidates[idx],ans,res); 
            res.pop_back(); //backtrack
        }
        helper(candidates,idx+1,target,ans,res); //We are not including the element
    }
        
    
};