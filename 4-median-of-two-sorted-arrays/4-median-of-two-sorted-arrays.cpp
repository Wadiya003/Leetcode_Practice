class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     int m=nums1.size();
     int n=nums2.size();
        int i=0;
        int j=0;
        int k =0;
       int temp[m+n];
        
        //sorting using two pointers
    while(i<m && j<n){
     if (nums1[i]<nums2[j]){
         temp[k++]=nums1[i++];
     }
    else{  
        temp[k++]=nums2[j++];
     }   
    }
        while(i<m){
 temp[k++]=nums1[i++];
     }
        while(j<n){
temp[k++]=nums2[j++];
        }
        // for(int i=0;i<m+n;i++){
        // cout<< temp[i];}
        
        
        //median
          if((m+n)%2 != 0)
            return (double)temp[(m+n)/2];
        else 
            return (double)(temp[((m+n) - 1) / 2] + temp[(m+n) / 2]) / 2.0;
    
    }
};