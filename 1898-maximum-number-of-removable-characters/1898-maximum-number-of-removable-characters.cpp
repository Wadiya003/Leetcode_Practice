class Solution {
public:
    bool isstillvalid(string s, string p, vector<int>& removable,int m){
        int i=0;
        int j=0;
        vector<bool> check(s.size(),true);
        for(int i=0;i<m;i++){
           check[removable[i]]=false;
        }
        while(i<s.size() and j<p.size()){
            
            if(p[j]==s[i] and check[i]==true){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        return j==p.size();
  }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l=0;
        int r=removable.size();
        int ans=0;
        while(l<=r){
          int m=l+(r-l)/2;
        if(isstillvalid(s,p,removable,m)){
        ans=m;
          l=m+1;
        }
        else {
         r=m-1;
        }
       
        } return ans;
    }
};