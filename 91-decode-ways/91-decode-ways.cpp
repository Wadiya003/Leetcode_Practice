class Solution {
public:
    int numDecodings(string s) {
        int n =s.length();
        int dp[n][2];
        
            //BASE CASES
        if(s[0]=='0')return 0; //np
        for(int i =0;i < n-1;i++){
            if(s[i]=='0'&& s[i+1]=='0')
                return 0; //np
        }
        if(n==1)return 1;//one one possible ans
            
        dp[0][0]=(s[1]!='0');//when we taking one element only if its not zero then return 1
        dp[0][1]=0;          //one element but in bundles would be 0 as no second element
        dp[1][0]=(s[1]!='0'); //two elements and one at time ->return 1 when second not zero
        dp[1][1]=(stoi(s.substr(0,2))<=26);//two elements and taking in bundles->if less than 26 return 1;
            //MAIN CONCEPT
        
        for(int i =2;i< n ; i++){
          //when taking single elements
            dp[i][0]= (s[i]=='0' || (i+1<n && s[i+1]=='0')) 
					? 0 
					: dp[i-1][0]+dp[i-1][1];//previous elements single or double
        //taking doubles elements 
            dp[i][1]= (s[i-1]=='0' ||  stoi(s.substr(i-1,2))>26) 
					? 0 
					: dp[i-2][0]+dp[i-2][1];//i-2th elements single or double
            
            }
        //add both case for answer
        return dp[n-1][0]+dp[n-1][1];
    }
};

