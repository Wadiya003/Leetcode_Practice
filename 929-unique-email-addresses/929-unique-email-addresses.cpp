class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>s;
        for(auto mail : emails){
            string temp;
            for(char c : mail){
                if(c=='+'|| c=='@')break;
                else if (c=='.')continue;
                temp+=c;
            }
            temp+=mail.substr(mail.find('@'));
            s.insert(temp);//no duplicate containing sets
        }
        return s.size();
    }
};