class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>cnt;
        vector<int>ans;
        for(int i=0;i<mat.size();i++){
            int k=0;
            for(int j=0;j<mat[i].size();j++){
			k+=mat[i][j];
			}
		cnt.push_back({k,i});   
        }
       sort(cnt.begin(),cnt.end());
        
    for(int i=0;i<cnt.size();i++){
     ans.push_back(cnt[i].second);
    }return vector<int>(ans.begin(),ans.begin()+k);
    }
};