class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int l=0;
        int h=chalk.size()-1;
        vector<long long int>v(chalk.size());
        v[0]=chalk[0];
        for(int i=1;i<chalk.size();i++){
        v[i]=v[i-1]+chalk[i];
        }
        k=k%v[h];
        
        
        while(l<h){
        int mid=l+(h-l)/2;
        if(v[mid]>k){
          h=mid;  
        }
       else l=mid+1;
            }
        return l;
    }
    
};  int l=0;
       
      