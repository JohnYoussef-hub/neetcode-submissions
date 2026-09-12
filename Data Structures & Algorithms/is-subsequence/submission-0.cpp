class Solution {
public:
    bool isSubsequence(string s, string t) {

        int sIt = 0;

        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == s[sIt]) sIt++;
        }

        return sIt == s.size();
    }
};