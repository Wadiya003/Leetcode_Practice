class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int pre = INT_MIN; 
        stack<int> s; 
        for (int i = nums.size()-1; i >= 0; --i) {
            if (nums[i] < pre ) return true; 
            while (s.size() && s.top() < nums[i]) {
                pre = max(pre, s.top()); 
                s.pop(); 
            }
            s.push(nums[i]); 
        }
        return false; 
        }
};