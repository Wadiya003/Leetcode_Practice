class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n =nums.size();
       int count=0,len=0;
    unordered_map<int,int>umap;
  
    for(int i=0;i<n;i++)
    {
        count+=nums[i]==1?1:-1;
        if(count==0)
        {
            len=max(len,i+1);
        }
        if(umap.find(count)!=umap.end())
        {
            len=max(len,i-umap[count]);
        }
        if(umap.find(count)==umap.end())
        {
            umap[count]=i;
        }
    }
    return len;
    
    
    }
};