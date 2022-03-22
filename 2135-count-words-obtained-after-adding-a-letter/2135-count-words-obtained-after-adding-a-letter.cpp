class Solution {
public://sort startwords and store in set
    //itarate on targetwords and remove chars from it ,then search in set if present increase cnt
    unordered_set<string>store;
    bool canbeformed(string check){
     for(int i =0;i<check.length();i++){
      string removed="";
     for(int j =0;j<check.length();j++){
       if(j==i){
       continue; //remove one letter at a time and check
       }
     removed.push_back(check[j]);}
     if(store.find(removed)!=store.end()){
         return true;
     }
     }return false;
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int cnt=0;
        for(auto i :startWords ){
            sort(i.begin(),i.end());
            store.insert(i);
            
        }
        for(auto j:targetWords){
            sort(j.begin(),j.end());
            if(canbeformed(j)){
                cnt++;
            }
        }return cnt;
    }
};