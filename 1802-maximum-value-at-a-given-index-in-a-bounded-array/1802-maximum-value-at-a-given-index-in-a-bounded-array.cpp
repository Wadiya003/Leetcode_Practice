class Solution {
public:
    //n ,+ve number, diff=0/1 , sum=maxsum
    bool fine(int mid,int n , int index,int maxsum){
        long m=mid;
        long l=index+1;
        long r=n-index;
        long sumleft=l<=m? l*(2*m-l+1)/2 : m*(m+1)/2 + (l-m);
        long sumright=r<=m? r*(2*m-r+1)/2 : m*(m+1)/2 + (r-m);
        long total=sumleft+sumright-m;
        return total<=maxsum;
        
    }
    int maxValue(int n, int index, int maxSum) {
   
        int l=1;
        int h=maxSum;
        int ans=0;
        while(l<h){
            int m =l+(h-l+1)/2;
            if(fine(m,n,index,maxSum)){
                l=m;
            }
            else{
                h=m-1;
            }
        }
        return l;
    }
};