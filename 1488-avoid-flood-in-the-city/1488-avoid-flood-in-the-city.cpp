class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int>rain;
        set<int>dry;
        vector<int>ans;
        for(int i =0; i<rains.size();i++){
            if(rains[i]==0){
                dry.insert(i);
                ans.push_back(1);
            }
            else{
                int lake=rains[i];
                if(rain.find(lake)!=rain.end()){
                    //if lake is filled
                    //find a day to dry it
                    auto it=dry.lower_bound(rain[lake]);
                    
                    if(it==dry.end()){
                        //cant find any day to dry it
                        return {};
                    }
                    //found day to dry lake 
                    int emptyit = *it; 
                    ans[emptyit] = lake; 
                    dry.erase(emptyit);
                    
                }
                rain[lake] = i; // Update that the lake became full on i-th day.
                ans.push_back(-1);
            }
        }
        return ans;
    }
};