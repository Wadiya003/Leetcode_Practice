class Solution {
public: //three pointer
    // int MOD=1e7;
    int threeSumMulti(vector<int>& arr, int target) {
        int ans=0;
        int MOD = 1000000007;
        sort(arr.begin(),arr.end());
        for(int i =0;i<arr.size();i++){
           int find=target-arr[i];
            int j =i+1;
            int k =arr.size()-1;
        while(j<k){
            if(arr[j]+arr[k]>find){
              k--;
            }
            else if(arr[j]+arr[k]<find){
                j++;
            }
            else if(arr[j]!=arr[k]){
                int l=1;
                int r=1;
                while(j+1<k && arr[j]==arr[j+1]){
                l++;
                j++;
                }
                while(k-1 > j && arr[k] == arr[k-1]){
                r++;
                k--;
                }
                ans+=l*r;
                ans%=MOD;
                j++;
                k--;   
            }else{//special case
                ans+= (k-j+1) * (k-j) / 2;
                ans%=MOD;
                break;
          }
        }
      }return ans;
    }
};