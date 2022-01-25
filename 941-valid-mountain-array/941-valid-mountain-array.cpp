class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
      int l=1;
      int peak=0;
      bool found=0;
      int r=arr.size()-2;
        if(arr.size()<3)return false;
        while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1] ){ 
            found=1;
            peak=mid; //local maxima
           break;
        }
        else if (arr[mid]<arr[mid+1]){
        l=mid+1;
        }
        else r=mid-1;}
    
    if(found==0)return false;
    for(int i=0;i<peak;i++){
        if(arr[i]>=arr[i+1]){
            return false;
        }
    }
     for(int i=peak;i<arr.size()-1;i++){
        if(arr[i]<=arr[i+1]){
            return false;
        }
    }return true;}
    
};