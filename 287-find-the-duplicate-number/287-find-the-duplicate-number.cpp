class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=0;
        for(auto a:nums){
           m[a]++;}
        for(auto a:m){
            if(a.second>1){
            ans=a.first;
            break;}
        }return ans;
    }
};