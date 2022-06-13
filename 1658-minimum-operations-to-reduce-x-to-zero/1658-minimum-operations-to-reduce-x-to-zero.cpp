class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();  
        int sum=0;
        int start=0,end=0;
        for(auto it:nums)
        {
            sum+=it;
        }
        if(sum<x)
        {
            return -1;
        }
        int r=sum-x;
        sum=0;
        int mini=-1;
        while(end<n)
        {
            sum+=nums[end];
            while(sum>r )
            {
                sum-=nums[start];
                start++;
            }
            if(sum==r)
            {
                mini=max(mini,end-start+1);
            }
            end++;
        }
        
        if(mini==-1)
        {
            return -1;
        }
        else
        {
            return n-mini;
        }
        
    }
};