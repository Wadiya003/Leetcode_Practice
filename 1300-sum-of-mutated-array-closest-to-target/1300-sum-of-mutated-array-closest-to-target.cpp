class Solution {
public:
    int check(int val,vector<int>& arr,int sum){
        int tot = 0;
        for(int i = 0; i < arr.size(); i++)
            tot += min(val, arr[i]);
        
        return abs(sum - tot);
        
    }
    int findBestValue(vector<int>& arr, int target) {
        int l=0;
        int r=target;
    
        while(l<r){
            int m =l+(r-l)/2;
            
            if(check(m, arr, target) <= check(m + 1, arr, target)) 
                r=m;
            else          
                l=m+1;
            }
            return r;
        }   

    };