class Solution {
public:  double dp[101][101];
       double solve(int pour,int row,int col){
           //end cases
           if(row<0|| row<col ||col<0){
          return 0.00;}
           if(row==0 && col==0){
               return pour;
           }
           if(dp[row][col]>-1){
              return dp[row][col];
           }
           double leftse=(solve(pour,row-1,col-1)-1)/2;
           if(leftse<0){
               leftse=0;
           }
           double rightse=(solve(pour,row-1,col)-1)/2;
           if(rightse<0){
               rightse=0;
           }
           double total=leftse+rightse;
           dp[row][col]=total;
           return total;
           
        }
    double champagneTower(int poured, int query_row, int query_glass) {
          memset(dp, -1, sizeof(dp));
        
       return min(1.00,solve(poured,query_row,query_glass));
    }
};