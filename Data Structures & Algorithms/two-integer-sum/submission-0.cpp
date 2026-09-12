class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> comps;

	for (int i = 0; i < nums.size(); i++)
	{
		int need = target - nums[i];
		if (!comps.count(need)) {
            comps[nums[i]] = i;
		}
		else 
			return {comps[need], i};
		
	}

	return vector<int>{};
}
};
