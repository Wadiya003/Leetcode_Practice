class Solution {
public:
    bool wecanreach(vector<int>& dist, double hour,int m){
        double sum=0;
        for(int i=0;i< dist.size();i++){
        if(i == dist.size()-1) sum += (double)dist[i]/m; 
        else sum += ceil((double)dist[i]/m);
        if(sum>hour)return false;
        }
        return true;
        
}
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (hour < dist.size() - 1) return -1;
        int l=1,r=1e7;
        int ans=-1;
        while(l<=r){
         int m=l+(r-l)/2;
        if(wecanreach(dist,hour,m)){
        ans=m;
        r=m-1;
        }
        else{
         l=m+1;
        }
        }
        return ans>1e7?-1:ans;
    }
};