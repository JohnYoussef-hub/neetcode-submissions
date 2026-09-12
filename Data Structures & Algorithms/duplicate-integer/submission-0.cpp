class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
	unordered_map<char, int> hm;
	for (int n : nums) {
		hm[n]++;
	}
	
	for (pair<char, int> p : hm) {
		if (p.second > 1) return true;
	}

	return false;
}
};