class Solution {
public:
    bool isvalid(int eat,vector<int>&piles,int h){
     int tot=0;
    for(int i=0;i< piles.size();i++){
       if(piles[i]%eat!=0)
                tot++;
        tot+=piles[i]/eat;
    }   
        return tot<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=0;
        int l=1;
        int r=1e9;
        // int r=accumulate(piles.begin(),piles.end(),0);
        while(l<=r){
        int m=l+(r-l)/2;
        if(isvalid(m,piles,h)){
        ans=m;
        r=m-1;
        }
        else{
         l=m+1;
        }
        }return ans;
    }
};