class Solution {
public: //dfs
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> indegree(n,0);
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        ans[i]=i;
        vector<vector<int> > graph(n);
        for(auto &x:richer)
        {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
         while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int n:graph[node])
            {
                if(quiet[ans[n]]>quiet[ans[node]])
                {
                    ans[n]=ans[node];
                }
               
                if(--indegree[n]==0)
                q.push(n);
            }
        }
        return ans;
    }
};