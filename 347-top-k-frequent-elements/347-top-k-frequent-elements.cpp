class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int>fre;
        if(k==nums.size()){
          return nums;
        }
        for(auto a : nums){
         fre[a]++;
        }
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(auto it:fre)
        {
            pq.push({it.second,it.first});
        }
        
        while(k--)
        {
            pair<int,int> p;
            p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};