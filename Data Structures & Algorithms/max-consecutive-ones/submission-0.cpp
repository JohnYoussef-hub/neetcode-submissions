class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int maxConsecutive = 0;
        int consecutive = 0;
        for (int n : nums) {
            if (n) 
                consecutive++;
            
            else {
                maxConsecutive = ::max(maxConsecutive, consecutive);
                consecutive = 0;
            }
        }
        return ::max(maxConsecutive, consecutive);
    }
};