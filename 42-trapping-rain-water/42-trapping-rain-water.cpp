class Solution {
public:
    
    int trap(vector<int>& height) {
    int n=height.size();
     // 2-pointer
    int ans=0,l=0,r=n-1;
    int leftm=0; 
    int rightm=0;
        while(l<=r){
          if(height[l]<=height[r]){
              if(leftm<height[l])
                  leftm=height[l];
              else ans+=leftm-height[l];
          l++;}
            else{
              if(rightm<height[r]){
                  rightm=height[r];
              }
              else ans+=rightm-height[r];  
               r--;
            }
        }return ans;}
        //dp
    //     if(height.empty())
    //     return 0;
    //     vector<int> leftm(n);
    //     vector<int> rightm(n);
    //     leftm[0]=height[0];
    //     rightm[n - 1] = height[n- 1];
    //     for(int i=1;i<n;i++){
    //       leftm[i]=max(leftm[i-1],height[i]);}
    //     for(int i=n-2;i>=0;i--){
    //       rightm[i]=max(rightm[i+1],height[i]);}
    //     for (int i = 1; i < n - 1; i++) {
    //     ans += min(leftm[i], rightm[i]) - height[i];}
    //     return ans;
    // }
};
