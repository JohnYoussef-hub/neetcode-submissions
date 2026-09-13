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

        for (int i = 0; i < s.size(); i++)
        {
            string decoded_string = "";
            string stringSize = "";

            if (s[i] == '#') {
                for (int j = i+1; j < s.size(); j++)
                {
                    if (s[j] == '0' || s[j] == '1'
                        || s[j] == '2' || s[j] == '3'
                        || s[j] == '4' || s[j] == '5'
                        || s[j] == '6' || s[j] == '7'
                        || s[j] == '8' || s[j] == '9') {
                        stringSize += s[j];
                    }
                    else break;
                }

                int size = stoi(stringSize);
				decodes.push_back(s.substr(i + stringSize.size() + 2, size));
				i += stringSize.size() + size + 1;

                stringSize = "";
                decoded_string = "";
                size = 0;
            }
        }

        return decodes;
    }
};