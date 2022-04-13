class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int ans=0;
        sort(position.begin(),position.end());
        int l=1;
        int r=999999999;
        while(l<=r){
        int force=l+(r-l)/2;
        if(canplacemballs(force,position,m)){
         ans=force;
        l=force+1;
        }
        else{
        r=force-1;
        }
      }
        return ans;
    }
    bool canplacemballs(int force,vector<int>& position, int m){
    int ball=1;            
    int lastballPosition=position[0];
    for(int i=1;i<position.size();i++)
    {
        if(position[i]-lastballPosition>=force)
        {
            ball++;
            lastballPosition=position[i];
            if(ball>=m) return true;
        }
    }
    return false;
    }
};