class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //map(remainder,index)
        unordered_map<int,int>m;
        //to avoid returning true in case the first num is a multiple of k.
        m[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           int r=sum%k;
            //if remainder seen before: means we got a valid subarr in between
           if(m.find(r)!=m.end()){
              if(i-m[r]>1){
                  return true;
              }
           }
           else{
             m[r]=i;
           }
        }
      return false;
    }
};