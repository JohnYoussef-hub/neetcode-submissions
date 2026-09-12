class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {

        int n = t.size();
        vector<int> res(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && t[i] > t[st.top()]) {
                int prevIdx = st.top();
                st.pop();

                res[prevIdx] = i - prevIdx;
            }
            st.push(i);
        }

        return res;
    }
};