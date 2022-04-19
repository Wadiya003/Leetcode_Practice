class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans=0,maxpro=0,j=0;
        vector<pair<int,int>>v;
        for(int i=0;i<difficulty.size();i++){
         v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        for(int i=0;i<worker.size();i++){
            while(worker[i]>=v[j].first && j<difficulty.size()){
            maxpro=max(maxpro,v[j].second);
            j++;
          
            }
            ans+=maxpro;
        }
        return ans;
    }
};

       
        
      