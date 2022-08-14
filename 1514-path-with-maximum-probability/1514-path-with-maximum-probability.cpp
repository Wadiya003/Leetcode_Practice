class Solution {
public:
    //djikstra algo
    void dfs(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end, int &val){
}
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //adjacency list
        vector<unordered_map<int, double>> graph(n);
        for(int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]][edges[i][1]] = succProb[i];
            graph[edges[i][1]][edges[i][0]] = succProb[i];
        }
        vector<double>maxprob(n,0.0);//probability of reaching each node
        maxprob[start]=1.0;
        queue<int>q;
        q.push(start);
        
        //bfs
        while(!q.empty()){
             int node=q.front();
             q.pop();
              for(auto &a:graph[node]){
                  int nn=a.first;//next node
                  double pp=a.second;//probability of node to nn
                  if(maxprob[node]*pp>maxprob[nn]){
                      //if reach this node with a larger probability, then push only
                    q.push(nn);
                    maxprob[nn] = maxprob[node] * pp;
                  }
              }
        }
        
        return maxprob[end];
    }
};