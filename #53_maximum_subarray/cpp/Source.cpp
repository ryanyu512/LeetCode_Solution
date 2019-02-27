#include<vector>
#include<iostream>

class Solution {
public:
	int maxSubArray(std::vector<int>& nums) {

		if (nums.empty())
			return 0;

		if (nums.size() == 1)
			return nums[0];

		int sum = 0, max_val = INT_MIN, cur_max_val = INT_MIN;
		int first_idx = -1, last_idx = -1;

		for (int i = 0; i < nums.size(); i++) {

			if (sum == 0)
				first_idx = last_idx = i;
			if (nums[i] + sum > cur_max_val) {
				last_idx = i;
				cur_max_val = nums[i] + sum;
			}
			sum += nums[i];

			if (sum < 0 || i == nums.size() - 1) {

				if (cur_max_val > max_val)
					max_val = cur_max_val;

				first_idx = i = last_idx;
				last_idx = -1;
				sum = 0;
				cur_max_val = INT_MIN;
			}
		}

		return max_val;
	}
};

int main() {

	Solution sol;
	
	std::vector<int> nums{-2, -3, 4, -5, 9};

	int sum = sol.maxSubArray(nums);

	std::cout << sum << std::endl;

	std::getchar(); std::getchar();
	return 0;
}