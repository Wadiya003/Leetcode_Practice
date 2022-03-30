class Solution {
public: //binary search //treat it as array only
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0;
        int r=matrix.size()*matrix[0].size()-1;
        while(l<=r){
        int mid=l+(r-l)/2;
            if(matrix[mid/m][mid%m]==target){
             return true;
            }
            else if(matrix[mid/m][mid%m]>target){
            r=mid-1;
            }else{
            l=mid+1;
            }
        }
        return false;
    }
};