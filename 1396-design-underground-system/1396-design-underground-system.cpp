class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>>checkin;
     unordered_map<string, pair<int,int>>allroute;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};   
    }
    
    void checkOut(int id, string stationName, int t) {
        string startToEnd = checkin[id].first + '-' + stationName; 
	allroute[startToEnd] = {allroute[startToEnd].first + (t - checkin[id].second), allroute[startToEnd].second + 1};
        checkin.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = allroute[startStation + '-' + endStation];
        return (double)p.first / p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */