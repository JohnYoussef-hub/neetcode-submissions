class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

		int maxArea = 0;
        stack<int> st;

        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[i] < heights[st.top()]) {

                int topIdx = st.top();
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

				int area = heights[topIdx] * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        return maxArea;
    }
};