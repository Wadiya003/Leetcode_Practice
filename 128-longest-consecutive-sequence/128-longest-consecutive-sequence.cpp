class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++){
       s.insert(nums[i]);
        }
        int count=0;
        int curr=0;
        int till=0;
        for(int i :s){
        if(!s.count(i-1)){ //first element of seqeunce
          curr=i;
          till=1;
            while(s.count(curr+1)){
              curr+=1;
              till+=1;
            }
            count=max(till,count);}
    }return count;
        
    }
};

    