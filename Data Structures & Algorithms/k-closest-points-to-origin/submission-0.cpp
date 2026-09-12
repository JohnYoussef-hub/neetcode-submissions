class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        
        priority_queue<pair<double, vector<int>>> maxHeap;

        for (auto point : points) {
            int x = point[0];
            int y = point[1];
            double d = sqrt(x * x + y * y);
            maxHeap.push({ d, point });
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};