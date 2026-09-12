class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        int greatest = -1;

        for (int i = n - 1; i >= 0; i--)
        {
            int currVal = arr[i];
            arr[i] = greatest;

            if (currVal > greatest) greatest = currVal;
        }
        return arr;
    }
};