class Solution {
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
       int n =points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mincost;
        //to get the min cost
        vector<bool> mst(n);
        //to make sure no cycle occurs
        mincost.push({0,0});
        int cost=0;
        int edges=0;
        //while we have n-1 edges
        while(edges<n){
            pair<int,int>top=mincost.top();//get smallest cost path
            mincost.pop();
            int w=top.first;//weight 
            int node=top.second;//node
            if(mst[node]){
                continue;//if already in arr,skip it 
            }
            mst[node]=true;//mark true 
            cost+=w;//add weight to total cost
            edges++;
            //update adjacent nodes
            for(int next=0;next<n;++next){
                if(!mst[next]){
                int nextw=abs(points[node][0]-points[next][0])+abs(points[node][1]-points[next][1]);
                    mincost.push({nextw,next});
                }
            }
        }
        return cost;
    }
};