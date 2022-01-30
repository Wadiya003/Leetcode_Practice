class Solution {
public:
     bool issafe(int row,int col ,int n , vector<string> &temp){
        int checkrow=row;
         int checkcol=col;
         //check for upper diag
         while(row>=0&&col>=0){
             if(temp[row][col]=='Q'){return false;}
             row--;
             col--;
         }
         row=checkrow;
         col=checkcol;
         //check for down diag
         while(row<n&&col>=0){
             if(temp[row][col]=='Q'){return false;}
         row++;
         col--;
         }
         row=checkrow;
         col=checkcol;
         while(col>=0){
             if(temp[row][col]=='Q'){return false;}
         col--;
         }return true;
     }
    
    void backtrack(int n,int col, vector<vector<string>>&ans, vector<string>& temp){
        if(col==n){
            ans.push_back(temp);
            return ;}
        for(int row=0;row<n;row++){
            if(issafe(row,col,n,temp)){
            temp[row][col]='Q';
            backtrack(n,col+1,ans,temp);//recursion
             temp[row][col]='.';//backtrack   
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> temp(n,string(n,'.'));
        backtrack(n,0,ans,temp);
        return ans;
    }};
// }; (Optimised Hashing)

// void cal(int j,int n,vector<string>&board,vector<vector<string>>&ans,vector<int>&left,vector<int>&upper,vector<int>&lower){
//     if(j==n){
//         ans.push_back(board);
//         return;
//     }
//     for(int i=0;i<n;i++){
//         if(left[i]==0 && lower[i+j]==0 && upper[n-1+(j-i)]==0){
//             board[i][j]='Q';
//             lower[i+j]=1;
//             left[i]=1;
//             upper[n-1+(j-i)]=1;
//             cal(j+1,n,board,ans,left,upper,lower);
//             board[i][j]='.';
//             lower[i+j]=0;
//             left[i]=0;
//             upper[n-1+(j-i)]=0;
//         }
//     }
// }
// class Solution {
// public:
     // vector<vector<string>> solveNQueens(int n) {
     //    string s(n,'.');
     //    vector<string>board(n);
     //    vector<vector<string>>ans;
     //    for(int i=0;i<n;i++){
     //        board[i]=s;
     //    }
     //    vector<int>left(n,0),upper(2*n-1,0),lower(2*n-1);        
     //    cal(0,n,board,ans,left,upper,lower);
     //    return ans;
     // }