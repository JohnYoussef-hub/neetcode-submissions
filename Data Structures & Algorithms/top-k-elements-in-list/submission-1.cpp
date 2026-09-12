class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>hm;

        for (int n : nums)
            hm[n]++;

        vector<int> res;

        pair<int, int> mostFreq = { INT_MIN, INT_MIN };
        while (res.size() < k) {
            for (auto pair : hm) {
                if (pair.second > mostFreq.second)
                    mostFreq = { pair.first, pair.second };
            }

            res.push_back(mostFreq.first);
            hm[mostFreq.first] = INT_MIN;
            mostFreq = { INT_MIN, INT_MIN };
            
        }

        return res;
    }
};