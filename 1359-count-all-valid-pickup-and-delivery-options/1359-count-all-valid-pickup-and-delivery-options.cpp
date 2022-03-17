class Solution {
public:int m= 1e9+7;

    
    int countOrders(int n) {
        long long total=1;
        for(int i =1;i<=n;i++){
            total*=i; //place pickups
            total%=m;
            total*=(2*i -1); //place deliveries
            total%=m;
        }
  
       return total%m;
    }
};