class TimeMap {

    unordered_map<string, vector<pair<int, string>>> keyStore;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { 
        keyStore[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int l = 0, r = values.size() - 1;
        string result = "";

        while(l <= r){
            int mid = l + (r - l)/2;
            if(values[mid].first <= timestamp) {
                result = values[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};
