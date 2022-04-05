class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0; int j=height.size()-1;
        int ans=0;
        while(i<j){
            int length=min(height[i],height[j]);
            ans=max(ans,(j-i)*length);
            while (height[i] <= length && i < j) i++;
             while (height[j] <= length && i < j) j--;    
             }return ans;
    }
};