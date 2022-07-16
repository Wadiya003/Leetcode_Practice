class Solution {
public:

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
     
        int n =routes.size();
        unordered_map<int,vector<int>> m; 
        unordered_map<int,bool>Station;
        vector<bool> Bus(n,false);
        queue<pair<int,int>> q;
        q.push({source,0});
        for(int i=0;i<n;++i){
            for(auto key : routes[i]){
                m[key].push_back(i);
            }
        }
      
        
        while(!q.empty()){
            
            int Node = q.front().first;
            int Val = q.front().second;
            if(Node == target) return Val;
            q.pop();
            Station[Node] = true;
            for(auto &b : m[Node]){
                if(Bus[b]) continue;
                for(auto &next : routes[b]){
                    if(Station.find(next) == Station.end()) 
                        q.push({next,Val+1});
                }
                Bus[b] = true;
            }
        }
        
        return -1;
    }
};