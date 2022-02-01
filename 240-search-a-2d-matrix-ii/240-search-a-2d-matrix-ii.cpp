class Solution {
public://BINARY-SEARCH
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      
        int m=0;
       
        int n =matrix[0].size()-1;
     
        while(m>=0 and n>=0 and m<matrix.size())
        {
            int num = matrix[m][n];
            if(num==target)
                return true;
            else if(num<target)
                m++;
            else
                n--;
        }
        return false;
    }
};
    