class Solution {
public://greedy
    int brokenCalc(int startValue, int target) {
        int ans=0;
     while(target>startValue){
       ans++;
       if(target%2==1){ //add
           target++;
       }  
       else{ //divide
          target/=2;}
     }return ans+startValue-target;
    }
};