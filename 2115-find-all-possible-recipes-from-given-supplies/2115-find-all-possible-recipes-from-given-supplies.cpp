class Solution {
public: //brute force
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,bool>haveit;
        vector<string>canmake;
        for(auto ing:supplies){
            haveit[ing]=true;
        }
        bool cancook=true;
        vector<int>madesofar(recipes.size(),0);
        while(cancook){
            cancook=false;
            for(int i=0;i<recipes.size();i++){
				if(madesofar[i])
				continue;

                int cnt=ingredients[i].size();
                for(auto ing:ingredients[i]){
                 if(haveit.find(ing)!=haveit.end()){
                 cnt--;
                 }
                }
                if(!cnt){ //canmake
                    canmake.push_back(recipes[i]);
                    cancook=true;
                    haveit[recipes[i]]=true;
                    madesofar[i]=1;
                    
                }
                
            }
        }return canmake;
      
    }
};