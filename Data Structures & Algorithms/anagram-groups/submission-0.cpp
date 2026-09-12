class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> words;

        for (string s : strs) {
            string word = s;
            ::sort(word.begin(), word.end());
            words[word].push_back(s);
        }


        vector<vector<string>> res;

        for (auto pair : words) {
            res.push_back(pair.second);
        }

        return res;
    }
};