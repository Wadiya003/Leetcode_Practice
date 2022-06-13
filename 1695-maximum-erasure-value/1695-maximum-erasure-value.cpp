class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0;
        int sum=0,res=0;
        unordered_map<int,int> m;
        while(j<nums.size()){
            if(m[nums[j]]){
                while(m[nums[j]]){ 
                    m[nums[i]]--;
                    sum-=nums[i];
                    i++;
                }
            }
            else{ 
                sum+=nums[j];
                res=max(res,sum); 
                m[nums[j]]++;
                j++;
            }
        }
        return res;

    }
};