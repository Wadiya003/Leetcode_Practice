class Solution {
public:
 
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>m;
        int both=0,top=0,bottom=0;
        //store frequency
        for(int i=0;i<tops.size();i++){
            m[tops[i]]++;
            m[bottoms[i]]++;
        }
        int max=0,res=-1;
        //find element with max freq
        for(auto i:m){
            if(max<i.second){
                res = i.first;
                max = i.second;
            }
        }
        //find freqency of max element in top , bottom and both 
        for(int i =0;i< tops.size();i++){
          if(tops[i]==res && bottoms[i]==res){
              both++;
           }
          if(tops[i]==res){
             top++;
            }
          if(bottoms[i]==res){
             bottom++;
            }
        }
         //check if there exists a valid answer
        if(top+bottom-both != tops.size()){
            return -1;
        }
        
        //if exists
        int ans=min(top,bottom)-both;
        return ans;
        
    }
};