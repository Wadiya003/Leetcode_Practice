class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0;
        int r=citations.size()-1;
        int ans=0;
        int n=citations.size();
        while(l<=r){
            int m=l+(r-l)/2;
            if(citations[m]>=n-m){
              ans=n-m;
              r=m-1;
            }
            else{
              l=m+1;
             }
          }
        return ans;
    }
};
        
      