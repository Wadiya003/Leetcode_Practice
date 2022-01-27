class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      priority_queue<pair<int,pair<int,int>>>p;  
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>res;
        for(int i=0;i<n1;i++){
         for(int j=0;j<n2;j++){
          if(p.size()<k){
              p.push(make_pair(nums1[i]+nums2[j],make_pair(nums1[i],nums2[j])));
          }
             else {if(p.top().first>nums1[i]+nums2[j]){
          p.pop();
         p.push(make_pair(nums1[i]+nums2[j],make_pair(nums1[i],nums2[j])));}
          
            else break;}
        
         }
        }
        while(!p.empty()){
         res.push_back({p.top().second.first,p.top().second.second});
            p.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

    
    
        