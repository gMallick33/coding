class UndergroundSystem {
public:

    map<int, pair<string, int>> checkInMap;
    map<string, pair<int, int>> routeAverageMap;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkInItems = checkInMap[id];
        checkInMap.erase(id);
        string route = checkInItems.first + "_" + stationName;
        routeAverageMap[route].first += t - checkInItems.second;
        routeAverageMap[route].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        return (double)routeAverageMap[route].first / routeAverageMap[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */