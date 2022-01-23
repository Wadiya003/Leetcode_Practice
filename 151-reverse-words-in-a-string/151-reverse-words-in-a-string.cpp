class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        //reverse string
       reverse(s,0,n-1);
        int i=0;
        int j=0;
        //reverse words
        while(i<n){
         while(i < n && s[i] == ' ')
            i++;
            j = i;
            while(j < n && s[j] != ' ')
                j++;
            reverse(s, i, j-1);
            i = j;
    }  
      //witespaces  
      int start=0;
        int end=0;
       
      while(end < n)
        { //leading spaces
            while(end < n && s[end] == ' ')
                end++;
            while(end < n && s[end] != ' ')
            {
                s[start] = s[end];
                start++;
                end++;
            }
          //following spaces
            while(end < n && s[end] == ' ')
                end++;
            if(end < n)
            {
                s[start] = ' ';
                start++;
            }
        }
        return s.substr(0,start);
    }
    void reverse(string &s,int i,int j){
      while(i<j){
     char a =s[i];
     s[i]=s[j];
      s[j]=a;
      i++;
      j--;}
    return;
    }
  
};