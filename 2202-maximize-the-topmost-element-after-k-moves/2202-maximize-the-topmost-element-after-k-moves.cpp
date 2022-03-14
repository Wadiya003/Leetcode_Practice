class Solution {
public: //greedy : choose either to add or del element 
    int maximumTop(vector<int>& nums, int k) {
        int result;
         if(k == 0) return nums[0]; //base case
        if(nums.size()==1 && k%2 !=0)return -1;
        int maxelement=0;
        int i=0;
        //find max element in k-1 turns;
        while(i < nums.size() && i < k-1){
            maxelement = max(maxelement, nums[i]);
            i++;
        }
        //now greedily choose whether to del in kth turn or add the max element 
        if(k<nums.size()) 
        result=nums[k];
        return max(maxelement , result);
    }
};