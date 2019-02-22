#include<iostream>
#include<vector>

class Solution {

public:
	int removeDuplicates(std::vector<int>& nums) {
		if (nums.size() == 0.f)
			return 0;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) {
				nums.erase(nums.begin() + i);
				i--;
			}
		}

		return nums.size();
	}
};

int main() {

	std::vector<int> nums{1, 1, 2};

	Solution sol;
	int length = sol.removeDuplicates(nums);

	for (int i = 0; i < length; i++)
		std::cout << nums[i] << ' ';

	std::cout << std::endl;

	std::getchar(); std::getchar();
	return 0;
}