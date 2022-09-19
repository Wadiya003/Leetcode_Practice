class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans;
        for(auto path: paths){
            int i = 0;
            while(path[i] != ' '){
                i++;
            }
            string dir = path.substr(0, i);
            while(i < path.size() - 1){
                
                int start = i + 1;  
                while(path[i] != '(') 
                i++;
                string file = path.substr(start, i-start); 
                start = i + 1;
                
                while(path[i] != ')') 
                i++;
                string content = path.substr(start, i- start); 
                m[content].push_back(dir + "/" + file);
                i++;
            }
        }
        
        
      for(auto a: m){
            if(a.second.size() > 1){
                ans.push_back(a.second);
            }
      }
       return ans;
    }
};