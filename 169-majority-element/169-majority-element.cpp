class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto n :nums){
            mp[n]++;
        }
        int n = nums.size();
        int m = int(n/2);

        for(int i=0;i<n;i++){
           if(mp[nums[i]]>m)return nums[i];      
        }
      return 0;
    }
};