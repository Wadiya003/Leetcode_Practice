class Solution {
public://OBSERVATION BASED
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        int repeat=1;
        v[0]=0;
        for(int i=1;i<=n;i++){
       if(repeat*2==i){
          repeat=repeat*2;
       }
        v[i]=1+v[i-repeat];}
         return v;  
    }
};