class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        bool isthere=false;
        for (int i=0;i<wordList.size();i++){
             if(endWord.compare(wordList[i])==0)
                isthere = true;
            st.insert(wordList[i]);
            
        }
        if(isthere==false)return 0;
        queue<string>q;
        q.push(beginWord);
        int depth=0;
        while(!q.empty()){
        depth+=1;
        int size=q.size();
        while(size--){
          string temp=q.front();
           q.pop();
            for(int j=0;j<temp.length();++j){
                string cur=temp;
                for(char c='a';c<='z';++c){
                 cur[j]=c;
                if(temp.compare(cur)==0)continue;
                if (cur.compare(endWord)==0) return depth+1;
                if(st.find(cur)!=st.end()){
                q.push(cur);
                st.erase(cur); 
                }   
              }
            }
          }
        }
     return 0;
    }
};