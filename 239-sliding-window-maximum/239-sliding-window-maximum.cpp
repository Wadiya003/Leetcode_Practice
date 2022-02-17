class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //brute force wont work =>tle
        //use deque to enter new elemet and delete firt element 
        deque<int> dq;
        vector<int>ans;
        for(int i =0;i <nums.size();i++){
  if (!dq.empty() && dq.front()==i-k){
 dq.pop_front();
  }
    while(!dq.empty()&& nums[dq.back()]<nums[i])
         dq.pop_back();
         dq.push_back(i);
            if (i>=k-1) 
            ans.push_back(nums[dq.front()]);
        
          
        }return ans;
    }
};