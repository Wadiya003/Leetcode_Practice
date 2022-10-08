class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n =nums.size();
        int minsum=INT_MAX;
        int res;
        sort(nums.begin(),nums.end());
        for(int i=0;i< n-2; i++){
        int j =i+1;
        int k =n-1;
       if(i > 0 && nums[i] == nums[i-1]) continue; //to avoid duplicates
        while(j<k){  
        int sum=nums[i]+nums[j]+nums[k];
        if(sum == target) return sum;
         if(abs(target-sum)<minsum) {
             
                minsum = abs(target - sum);
           
                res = sum;
            }
         if(sum>target){
             k--;}
         if(sum<target){
         j++;}
         }}
        return res;
    }
};