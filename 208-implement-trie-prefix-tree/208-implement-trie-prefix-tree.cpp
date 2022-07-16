
class TrieNode {
public:
    bool isword;
    TrieNode *children[26];
    
    TrieNode() {
        isword = false;
        
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int len = word.length();
        TrieNode *cur = root;
        int let = 0;
        for (int i = 0; i < len; i++)
        {
            let= word[i] - 'a';
            
            if (cur->children[let] == NULL)
            {
                cur->children[let] = new TrieNode();
            }
            
            cur = cur->children[let];
        }
        
        cur->isword = true;
    }
    
    bool search(string word) {
        int len = word.length();
        TrieNode *cur = root;
        int let = 0;
        for (int i = 0; i < len; i++)
        {
            let = word[i] - 'a';
            cur = cur->children[let];
            
            if (cur == NULL)
                return false;
        }
        
        return cur->isword;
    }
    
    bool startsWith(string prefix) {
        int len = prefix.length();
        TrieNode *cur = root;
        int let = 0;
        for (int i = 0; i < len; i++)
        {
            let = prefix[i] - 'a';
            cur = cur->children[let ];
            
            if (cur == NULL)
                return false;
        }
        
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */