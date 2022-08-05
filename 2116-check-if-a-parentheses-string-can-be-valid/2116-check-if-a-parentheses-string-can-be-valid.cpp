class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2==1){
            return false;
        }
        if(isValid(s)){
            return true;
        }
       int balance = 0;
        int flip = 0;
          for(int i = 0; i < s.length(); i++) {
            if(locked[i] == '0') {
                flip++;
            } else {
                if(s[i] == '(') {
                    balance++;                    
                } else {
                    balance--;
                }                
            }
            if(balance + flip < 0) {
                return false;
            } 
        }
        if(balance > flip) {
            return false;
        }
        
        balance = 0;
        flip = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(locked[i] == '0') {
                flip++;
            } else {
                if(s[i] == ')') {
                    balance++;                    
                } else {
                    balance--;
                }                
            }
            if(balance + flip < 0) {
                return false;
            } 
        }
        if(balance > flip) {
            return false;
        }
        return true;
        
    }
        
    
     private: bool isValid(string s) {
        int balance = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                balance++;
            } else {
                balance--;
            }
            if(balance < 0) {
                return false;
            }
        }
        if(balance != 0) {
            return false;
        }
        return true;
    }
};