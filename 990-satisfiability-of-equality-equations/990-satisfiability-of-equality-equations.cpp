class Solution {
private: 
    vector<vector<int>>adj;
    vector<int>vis;
    vector<int>col;
public:
    bool equationsPossible(vector<string>& equations) {
        int n =equations.size();
        int alp=26;
        adj.resize(alp),vis.resize(alp,0),col.resize(alp);
        for(auto e:equations){
        //if they are equal , connect them and same color them
        if(e[1]=='='){
            char a=e[0];
            char b=e[3];
            adj[a-'a'].push_back(b-'a');
            adj[b-'a'].push_back(a-'a');  
        }
        }
        //color them
        int color=0;
        for(int i=0;i<alp;i++){
        if(!vis[i]){
           dfs(i,color); 
        }
        color++;
        }
        //check
        for(auto e:equations){
        if(e[1]=='!'){
            char a=e[0];
            char b=e[3];
            //shouldn't be of same color
            if(col[a-'a']==col[b-'a'])return false;
        }    
        }
        return true;
    }
    void dfs(int i, int color){
        vis[i]=1;
        col[i]=color;
        for(auto a:adj[i]){
            if(!vis[a])dfs(a,color);
        }
    }
};