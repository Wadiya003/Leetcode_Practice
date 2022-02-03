class Solution {
public:
    string removeKdigits(string num, int k) {
       //Base Cases
        if(num.length() <= k)
            return "0";
        if(k == 0)
            return num;
        
        stack <char> s;
        s.push(num[0]);
        
        for(int i = 1; i<num.length(); i++){
            while(k>0 && !s.empty() && num[i]<s.top()){
                k--;
                s.pop();
            }
            s.push(num[i]);
            
			
            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }
        
		// EDGE CASE: For cases like "12345" where every str[i] > s.top()
		while(k && !s.empty()){
		k--;
		s.pop();
		}
        string res = "";
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        if(res.size() == 0)
            return "0";
        else
        return res;
    
    }
};