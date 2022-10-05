class Solution {
public:
    bool recur(bool alice, int rem0,int rem1,int rem2, int mul3){
     if(mul3==0 || rem0<0 || rem1<0 || rem2<0){
          //no divisiblity by 3-> alice wins
      return true;
     }
     if(rem0==0 && rem1==0 && rem2==0){
         //no stone left-> bob winning
      return !alice;
     }

        //bob's turn->he must lose in order for alice to win
      return 
          !recur(!alice, rem0-1,rem1,rem2,mul3)||
          !recur(!alice, rem0,rem1-1,rem2,(mul3+1)%3)||
          !recur(!alice,rem0,rem1,rem2-1,(mul3+2)%3);
        
    
    }
    bool stoneGameIX(vector<int>& stones) {
        if(stones.size()==1){
            return false;
        }
         vector<int>v(3);
         for (auto s : stones)
         v[s%3]++;
         return recur(1, v[0] % 2, v[1], v[2], 3);
        
    }
};