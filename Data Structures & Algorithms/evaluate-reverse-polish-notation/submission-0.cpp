class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto s : tokens) {
            if (s == "+" or s == "-" or s == "*" or s == "/") {
                int n1 = st.top(); st.pop();
                int n2 = st.top(); st.pop();

                int res;
                if (s == "+") res = n2 + n1;
                else if (s == "-") res = n2 - n1;
                else if (s == "*") res = n2 * n1;
                else if (s == "/") res = n2 / n1;

                st.push(res);
            }
            else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};