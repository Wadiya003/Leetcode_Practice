class Solution {
public:
    void helper(long long num,int n,int k,vector<int> &ans){
        if(n==0){
            ans.push_back(num);
            return;
        }
        int low=((num==0)?1:0);
        for(int i=low;i<10;i++){
            if(num and abs(i-num%10)!=k) continue;
            num*=10;num+=i;
            helper(num,n-1,k,ans);
            num/=10;
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        long long num=0;
        helper(num,n,k,ans);
        return ans;  
    }
};