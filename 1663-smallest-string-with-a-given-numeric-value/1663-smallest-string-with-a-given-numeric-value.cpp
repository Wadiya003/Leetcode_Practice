class Solution {
public: //greedy 
    string getSmallestString(int n, int k) {
        string temp="";
        int rem=0;
        for(int i=0;i<n;i++){
           temp+='a';
            rem++;
        }
        k-=rem;
      for(int i=n-1;i>=0;i--)
        {
            if(k==0)
                break;
             else if(k>25){
                 temp[i]='z';
                 k-=25;
              }
          else {
            temp[i] = (char)('a'+k);       
                k=0;
          }
      }return temp;
    }
};