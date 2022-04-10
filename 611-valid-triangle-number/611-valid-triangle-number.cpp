class Solution {
public://sum of its two sides is greater than the third side
    //only one condition a + b > ca+b>c would suffice. This happens because c ≥ b and c ≥ a
    //therefore  a < b < c
    int triangleNumber(vector<int>& nums) {
       int ans=0;
        int n =nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int k =i+2;
             for(int j =i+1;j<n-1 && nums[i]!=0;j++){
                 k=binary(k,n-1,nums,nums[i]+nums[j]);
                 ans+=k-j-1;
              }    }
        return ans;
    }
    int binary(int s,int e,vector<int>& nums, int sum){
        while(s<=e){
              int mid = (s + e) / 2;
            if (nums[mid] >= sum)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return s;
         }
    
};