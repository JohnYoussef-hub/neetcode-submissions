class Solution {
public:
    bool isAnagram(string s, string t) {
	unordered_map<char, int> hm;
	
	for (char c : s) {
		hm[c]++;
	}

	for (char c : t) {
		if (!hm.count(c)) return false;
		else {
			hm[c]--;
			if (hm[c] < 0) return false;
		}
	}

    for(const pair<char, int>& p : hm) {
        if (p.second != 0) return false;
	}

	return true;
}
};
