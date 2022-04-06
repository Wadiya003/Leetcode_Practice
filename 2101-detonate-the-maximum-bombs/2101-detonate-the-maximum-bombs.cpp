class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> graph(bombs.size());
for (int i = 0; i < bombs.size(); ++i) {
    long long x = bombs[i][0], y = bombs[i][1], r2 = (long long)bombs[i][2] * bombs[i][2];
        for (int j = 0; j < bombs.size(); ++j)
            //add in graph if and only if radius overlapss
 if ((x - bombs[j][0]) * (x - bombs[j][0]) + (y - bombs[j][1]) * (y - bombs[j][1]) <= r2)
                graph[i].push_back(j); 
           }
        
        //bfs : check for every node 
        int ans=1;
        for(int i=0;i<bombs.size() && ans<bombs.size();i++){
            queue<int>q;
            q.push(i); //0
           vector<bool>vis(bombs.size(), 0);
            int cnt=0;
            while(!q.empty()) {
                int n = q.size();//1
                for(int i = 0; i < n; i++) {
                    int x = q.front();//0
                    q.pop();
                    vis[x] = 1;
                    cnt++;
                    for(auto p : graph[x]) { //graph[0]: where can i reach from 
                        if(!vis[p]) {
                            q.push(p);
                            vis[p] = 1;
                        }
                    }
                }
            }
            ans=max(ans,cnt);
}return ans;
    }
};