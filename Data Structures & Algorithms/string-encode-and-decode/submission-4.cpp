class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";

        for (string s : strs) {
            encoded_string += "#" + ::to_string(s.size()) + "#" + s;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decodes;

        int i = 0;

        while (i < s.size()) { // #5#Hello
            i++;

            int j = i;

            while (s[j] != '#') 
                j++;
            
            int size = std::stoi(s.substr(i, j - i));

            j++;

            decodes.push_back(s.substr(j, size));

            i = j + size;
        }
        return decodes;
    }
};
