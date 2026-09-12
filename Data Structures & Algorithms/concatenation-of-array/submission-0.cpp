class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        vector<int> res(nums.begin(), nums.end());

        for (int n : nums) {
            res.push_back(n);
        }

        return res;
    }
};