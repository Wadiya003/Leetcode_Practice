class Solution {
public:
  double dfs(unordered_map<string, vector<pair<string, double>>> &g, unordered_set<string> vis, string start, string end){
		if(g.find(start) == g.end() || g.find(end) == g.end()) return -1.0; 

		if(start == end) return 1.0; 
		vis.insert(start); 

		for(auto next : g[start]){
			if(vis.count(next.first)==0){
				double res = dfs(g, vis, next.first, end);

				if(res != -1.0){
					return res*next.second;
				}
			}
		}
		return -1.0;
	} 
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            auto f = equations[i][0];
            auto t = equations[i][1];
            double weight = values[i];  
            graph[f].push_back({t, weight});
            graph[t].push_back({f, 1 / weight});
        }
        
        for (auto q: queries) {
            unordered_set<string> vis; 
			double res = dfs(graph, vis, q[0], q[1]);  
			ans.push_back(res);
        }
        
        return ans;
    }
};