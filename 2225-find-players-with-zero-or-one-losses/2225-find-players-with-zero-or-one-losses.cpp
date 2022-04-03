class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>win,lose;
        vector<vector<int>>ans;
        vector<int>winn,loss;
        for(auto match:matches){
        lose[match[1]]++;
       
        }
        for(auto match:matches){
      if(lose.find(match[0])==lose.end()){
        win[match[0]]++;}
        }
        for(auto m:win){
           winn.push_back(m.first);}
        
        for(auto m:lose){
         if(m.second==1){
         loss.push_back(m.first);
       }
        }
        sort(winn.begin(),winn.end());
        ans.push_back(winn);
        sort(loss.begin(),loss.end());
        ans.push_back(loss);
        return ans;
        
    }
};