class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> target;
        for (char c : t) target[c]++;

        int left = 0, right = 0, count = 0;
        int minLen = INT_MAX, startIdx = 0;
        unordered_map<char, int> window;

        while (right < s.length()) {
            char c = s[right];
            if (target.count(c)) {
                window[c]++;
                if (window[c] == target[c]) count++;
            }

            while (count == target.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                if (target.count(leftChar)) {
                    if (window[leftChar] == target[leftChar]) count--;
                    window[leftChar]--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};