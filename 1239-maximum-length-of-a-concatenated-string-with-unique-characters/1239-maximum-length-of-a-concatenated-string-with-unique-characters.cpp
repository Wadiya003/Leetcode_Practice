class Solution {
public:
    //dfs : recursive : try for each cases : take a string or not take it 
    bool is_not_unique(string &s){
         int arr[26]={0};
    for(int i=0;i<s.length();i++){
        arr[ s[i]-'a' ]++;
        if( arr[s[i]-'a'] > 1 )return false;
    }
    return true;
    }
    
    void helper(vector<string>&arr, string cur, int &ans, int i, int n){
      if(i==n){
          //final case
          //update ans 
             if(is_not_unique(cur)){
             int ss=cur.length();
             ans=max(ans,ss);
             }
          return;  
      }
      helper(arr,cur+arr[i],ans,i+1,n);
      helper(arr,cur,ans,i+1,n);
    }
    
    int maxLength(vector<string>& arr) {
      int ans=INT_MIN;
      string str="";
      helper(arr, str, ans, 0,arr.size());
      return ans;
    }
};