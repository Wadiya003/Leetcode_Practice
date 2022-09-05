class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int sz=edges.size();
        vector<int> in(n);
        for(int i=0;i<sz;i++){
        in[edges[i][1]]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
        if(in[i]==0){
            ans.push_back(i);
        }
        }
        return ans;
    }
};
