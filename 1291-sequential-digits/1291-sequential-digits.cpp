class Solution {
public:vector<int>ans;
    vector<int> sequentialDigits(int low, int high) {
       for(int i=1;i<=9;i++){
           helper(low,high,i,0);
       } 
        sort(ans.begin(),ans.end());
        return ans;
    }
    void helper(int low,int high,int i,int num){
    
    
    if(num>=low&&num<=high){
        ans.push_back(num);
       
    }
     if(i>9)return;
    helper(low,high,i+1,num*10+i);}
};


