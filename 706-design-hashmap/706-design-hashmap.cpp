class MyHashMap {
public:
    vector<vector<pair<int,int>>>map;
    int size=1e4;
    MyHashMap() {
        map.resize(size);
    }
    
    void put(int key, int value) {
        int ind = key % size;
        vector<pair<int, int>> &row = map[ind];
        for(auto it = row.begin(); it != row.end(); it++)
        {
            if(it->first == key)
            {
                it->second = value;
                return;
            }
        }
		row.push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int ind = key % size;
        vector<pair<int, int>> &row = map[ind];
		for (auto it = row.begin(); it != row.end(); it++)
		{
			if (it->first == key)
			{
				return it->second;
			}
		}
		return -1;
    }
    
    void remove(int key) {
        int ind = key % size;
        vector<pair<int, int>> &row = map[ind];
		for (auto it = row.begin(); it != row.end(); it++)
		{
			if (it->first == key)
			{
				row.erase(it);
                return;
			}
		}
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */