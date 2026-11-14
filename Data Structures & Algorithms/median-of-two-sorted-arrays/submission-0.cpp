class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		priority_queue<int> maxHeap; // Max heap for the left half

		for (int num : nums1) {
			maxHeap.push(num);
		}

		for (int num : nums2) {
			maxHeap.push(num);
		}

		vector<int> mergedArray;
		while (!maxHeap.empty()) {
			mergedArray.push_back(maxHeap.top());
			maxHeap.pop();
		}

		int totalSize = mergedArray.size();

		if (totalSize % 2 == 1) {
			return mergedArray[totalSize / 2]; // If odd, return the middle element
		}

		else {
			// If even, return the average of the two middle elements
			int mid1 = mergedArray[totalSize / 2 - 1];
			int mid2 = mergedArray[totalSize / 2];
			return (mid1 + mid2) / 2.0;
		}
    }
};