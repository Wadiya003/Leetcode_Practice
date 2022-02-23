class Solution {
public://recusrion + Memoziation
    unordered_map<string,int>m; 
    bool solve(string s1, string s2){
        if(s1.length()!=s2.length()){
            return false;
        }
        if(s1==s2){
            return true;
        }
          if(s1.length()==1)
            return s1==s2;
        string temp=s1+' '+s2;
        if(m.find(temp)!=m.end()){
         return m[temp];}
        int n =s1.length();
        for(int i=1;i<s1.length();i++){
           if( solve(s1.substr(0,i), s2.substr(0,i)) && solve(s1.substr(i), s2.substr(i)))
                return m[temp]=true;
            if( solve(s1.substr(0,i), s2.substr(n-i)) && solve(s1.substr(i), s2.substr(0,n-i)))//reersed/flipped case
                return m[temp]=true ;  
    }return m[temp]= false;       
    }
    bool isScramble(string s1, string s2) {
      return solve(s1,s2);
    }
};