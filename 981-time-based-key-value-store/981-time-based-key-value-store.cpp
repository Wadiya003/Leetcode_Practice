class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>m;
    string search(vector<pair<int,string>> &v , const int &timestamp){
        int l=0;
        int h=v.size()-1;
       
        while (l<= h) {
            int mid = l + (h - l) / 2;
            
            if (v[mid].first > timestamp) {
                h = mid - 1;
            } else if (v[mid].first < timestamp) {
                l = mid + 1;
            } else {
                return v[mid].second;
            }
        }
        
        return h >= 0 ? v[h].second : "";
    }
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end())
            return "";
       return search(m[key],timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */