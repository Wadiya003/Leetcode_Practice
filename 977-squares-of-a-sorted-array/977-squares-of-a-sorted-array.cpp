class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>v(nums.size());
        int j=0, k=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(abs(nums[j])>abs(nums[k])){
             v[i]=nums[j]*nums[j];
              j++;
            }
            else{
                v[i]=nums[k]*nums[k];
                k--;
            }
            
         }
        return v;
    }
};