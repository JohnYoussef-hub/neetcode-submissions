class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
	unordered_set<int> hm;
	for (int n : nums) {
		if (hm.count(n)) return true;
		hm.insert(n);
	}

	return false;
}
};