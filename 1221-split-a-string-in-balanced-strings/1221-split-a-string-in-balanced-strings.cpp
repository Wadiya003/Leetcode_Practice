class Solution {
public:
    int balancedStringSplit(string s) {
       int n=s.length();
        int count=0;
        int balance=0;
        for(int i=0; i< n;i++){
            if(s[i]=='L'){
                balance++;
            }
             else if(s[i]=='R'){
                balance--;
            }
             if(balance==0){
                 count+=1;
            }
            
          }return count;
        
    }
};