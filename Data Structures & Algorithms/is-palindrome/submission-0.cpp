class Solution {
public:
    bool isPalindrome(string s) {
        int first = 0;
        int last = s.size() - 1;

        while (first < last) {
            if (!isalnum(s[first])) 
                first++;
            
            else if (!isalnum(s[last])) 
                last--;
                           
            else {
                if (tolower(s[first]) != tolower(s[last])) 
                    return false;
                
                first++;
                last--;
            }
        }

        return true;
    }
};