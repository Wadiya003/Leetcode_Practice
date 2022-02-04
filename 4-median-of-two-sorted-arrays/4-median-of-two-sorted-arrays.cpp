class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//      int m=nums1.size();
//      int n=nums2.size();
//         if(m>n){
//             return findMedianSortedArrays(nums2,nums1);
//         }
        
    
//         int l=0;
//         int h=m;
//         int tot=m+n;
//         double medium=0.0;
//         while(l<=h){
//             int aleft=l+(h-l)/2;
//             int bleft=(tot+1)/2-aleft;
//              int ab=(aleft==0)?INT_MIN:nums1[aleft-1];
//              int aa=(aleft==m)?INT_MAX:nums1[aleft];
//              int bb=(bleft==0)?INT_MIN:nums2[bleft-1];
//              int ba=(bleft==n)?INT_MAX:nums2[bleft];
//             //valid segragation
//             if(ab<=ba&&bb<=aa){
//                 //calculate median
             
//                 //even
//                  if(tot%2==0){
//                   int lmax=max(ab,ba);
//                   int rmin=max(aa,bb);
//                   medium=(lmax+rmin)/2;
//                      //cout<<medium<<endl;
//                  }
//                 //odd
//                 else{
//                     int lmax=max(ab,ba);
//                     medium=lmax;
//                     // cout<<medium<<endl;
//                 }
              
//             }
//             else if(ab>ba){
//               h=aa-1;  
//             }
//             else if(bb>aa){
//               l=aa+1; 
//             }
//         }
//         return medium;
        
         if(nums2.size() < nums1.size())
       return findMedianSortedArrays(nums2, nums1);
       int n1 = nums1.size();
       int n2 = nums2.size();
       int lo = 0, hi = n1;
       while(lo<=hi)
       {
           int cut1 = (lo+hi) /2;
           int cut2 = (n1+n2+1)/2 - cut1;
           int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
           int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];

           int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
           int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

           if(left1 <= right2 && left2 <= right1)
           {
               if((n1+n2)%2 == 0)
               return (max(left1, left2)+min(right1, right2))/2.0;
               else
               return max(left1, left2);
           }
           else if(left1 > right2)
           {
               hi = cut1 - 1;
           }
           else
           lo = cut1+1;
       }
       return 0.0;
    }
        
//         int i=0;
//         int j=0;
//         int k =0;
//        int temp[m+n];
        
//         //sorting using two pointers
//     while(i<m && j<n){
//      if (nums1[i]<nums2[j]){
//          temp[k++]=nums1[i++];
//      }
//     else{  
//         temp[k++]=nums2[j++];
//      }   
//     }
//         while(i<m){
//  temp[k++]=nums1[i++];
//      }
//         while(j<n){
// temp[k++]=nums2[j++];
//         }
//         // for(int i=0;i<m+n;i++){
//         // cout<< temp[i];}
        
        
//         //median
//           if((m+n)%2 != 0)
//             return (double)temp[(m+n)/2];
//         else 
//             return (double)(temp[((m+n) - 1) / 2] + temp[(m+n) / 2]) / 2.0;
    
    
};