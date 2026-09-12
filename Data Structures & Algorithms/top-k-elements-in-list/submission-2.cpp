class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>hm;

        for (int n : nums)
            hm[n]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto [num, freq] : hm) {
            minHeap.push({ freq, num });

            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> res;

        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};