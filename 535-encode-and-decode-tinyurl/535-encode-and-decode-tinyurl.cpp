class Solution {
public:
    unordered_map<string, string> encod,decod;
    const string from = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string making() {
      string make = "";
        for (int i = 0; i < 6; i++) 
            make += from[rand() % 62];
        return "http://tinyurl.com/" + make;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
       if(decod.find(longUrl)!=decod.end()) return decod[longUrl];
        
        string temp =making();
        while (encod.find(temp) != encod.end()) temp = making();
        encod[temp] = longUrl;
        decod[longUrl] = temp;
        return temp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return encod[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));