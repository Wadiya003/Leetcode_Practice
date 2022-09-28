class Solution {
public:
    string pushDominoes(string dominoes) {
        int n =dominoes.length();
        queue<pair<int,char>>q;
        for(int i =0;i< n;i++){
        if(dominoes[i]!='.'){
            q.push({i,dominoes[i]});
        }
        }
        
        while(!q.empty()){
            pair<int,char>p=q.front();
            int i=p.first;
            char d=p.second;
            q.pop();
              if(d == 'R') {
                if(i + 1 < n && dominoes[i + 1] == '.') {
                    if(i + 2 < n && dominoes[i + 2] == 'L') { 
                        q.pop();
                    }
                    else {
                        q.push({i + 1, 'R'});
                        dominoes[i + 1] = 'R';
                    }
                }
            }
            else { 

                if(i > 0 && dominoes[i - 1] == '.') {
                    q.push({i - 1, 'L'});
                    dominoes[i - 1] = 'L';
                }
            }
            
        }
        return dominoes;
    }
};