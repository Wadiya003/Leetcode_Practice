class Solution {
public: //BASIC IDEA->AFTER SORTING EVEN AND ODD INDEXED LETTERS , WE WILL GET SAME STRING 
    int numSpecialEquivGroups(vector<string>& words) {
set<pair<string,string>>s ;
        for(auto word: words){
        pair<string,string> p;
        for (int i = 0; i < word.size (); ++i) {
            if (i % 2) p.first  += word[i];// odd 
            else       p.second += word[i]; //even 
        }
        sort (p.first.begin  (), p.first.end ());
        sort (p.second.begin (), p.second.end ());
        s.insert (p);
    }//unique pairs size
    return s.size ();
    }
};