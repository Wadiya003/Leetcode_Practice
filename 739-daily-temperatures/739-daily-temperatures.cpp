class Solution {
public:
    // use a stack of indexes 
    vector<int> dailyTemperatures(vector<int>& temperatures) {
     stack<int>s;
     vector<int> ans(temperatures.size(),0);
     for(int i=temperatures.size()-1;i>=0;i--){
     
      while(!s.empty() && temperatures[s.top()] <= temperatures[i]){
            s.pop();
      }
      if(!s.empty())
            ans[i] = s.top()-i; 
      s.push(i);
     }
     return ans;
    }
};