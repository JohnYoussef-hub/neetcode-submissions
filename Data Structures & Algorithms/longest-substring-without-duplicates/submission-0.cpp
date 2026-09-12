class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> hm;
        int l = 0, r =0;
        int maxLength = 0;

        while(r < n){
            if(hm.count(s[r])){
                hm.erase(s[l]);
                l++;
            }
            else{
                hm.insert(s[r]);
                r++;
            }

            maxLength = std::max(maxLength, (int)hm.size());
        }
        return maxLength;
    }
};
