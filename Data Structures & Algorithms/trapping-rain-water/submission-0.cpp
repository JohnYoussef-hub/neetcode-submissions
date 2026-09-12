class Solution {
public:
    int trap(vector<int> h) {

        int l = 0, r = h.size() - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (l < r) {
            if (h[l] < h[r]) {
                if (h[l] > leftMax)
                    leftMax = h[l];
                else
                    totalWater += leftMax - h[l];

                l++;
            }
            else {
                if (h[r] > rightMax)
                    rightMax = h[r];
                else
                    totalWater += rightMax - h[r];

                r--;
            }
        }
        return totalWater;
    }
};