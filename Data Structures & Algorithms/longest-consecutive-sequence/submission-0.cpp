class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs(nums.begin(), nums.end());
        int longest = 0;

        for (int n : hs) {
            if (!hs.count(n - 1)) {
                int currNumber = n;
                int currLength = 1;

                while (hs.count(currNumber + 1)) {
                    currNumber++;
                    currLength++;
                }

				longest = max(longest, currLength);
            }
        }

        return longest;
    }
};
