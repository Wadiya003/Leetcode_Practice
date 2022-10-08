class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
    unordered_map<int, unordered_set<int>> adj;
    set<int>vis;
	for(int i=0; i<pairs.size(); i++){
		adj[pairs[i][0]].insert(pairs[i][1]);
		adj[pairs[i][1]].insert(pairs[i][0]);
	}
    priority_queue<pair<int,int>>pq;
        for(auto& [node,fre]: adj){
            pq.push(make_pair(fre.size(),node));
        }
    int ans=1;
    int totalnodes=pq.size();
        while(!pq.empty()){
            pair<int,int>top=pq.top();
            pq.pop();
            int fre=top.first;
            int node=top.second;
            int parent=-1;
            int findParent=INT_MAX;
            for(auto &a:adj[node]){
                if(vis.count(a) && adj[a].size()<findParent && adj[a].size()>=fre){
                    parent=a;
                    findParent=adj[a].size();
                }
            }
            vis.insert(node);
            //current node is the parent node
            if(parent==-1){
                //if it doesn't connect everynode
               if(fre!=totalnodes-1){
                  return 0;
               }
            continue;
            }
            //parent must connect to all current node's neighbors
            for(auto &neighbour : adj[node]){
			if(neighbour == parent)
                //is a parent->don't need to check ahead in adj list 
            {continue;}
			if(!adj[parent].count(neighbour))
                //parent's adj list doesn't contain a node of adj list
            {return 0;}
		    }
            
		    if(fre == findParent){
			ans = 2;
            }
        }
        
        return ans;
    }
};