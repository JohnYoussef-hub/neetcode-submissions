class TimeMap {
	unordered_map<string, vector<pair<int, string>>> data;
public:
    TimeMap() {
		data.clear();
    }

    void set(string key, string value, int timestamp) {
		data[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if(data.find(key) == data.end()) 
            return "";

        string res;

        const auto& v = data[key];

        int l = 0;
        int r = v.size() - 1;

        while (l <= r) {
			int mid = l + (r - l) / 2;

            if (v[mid].first <= timestamp) {
                res = v[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};