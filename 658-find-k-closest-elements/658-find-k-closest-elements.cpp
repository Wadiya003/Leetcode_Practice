class Solution {
public: //sliding window technique 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0;
        int r=arr.size()-k;
        while(l<r){
         int m=l+(r-l)/2;
        if(x-arr[m]>arr[m+k]-x){
            l=m+1; //discard left part
        }
        else{
           r=m; //discard right part
        }
        }
        return vector<int>(begin(arr) +l, begin(arr) + l+k);
    }
};