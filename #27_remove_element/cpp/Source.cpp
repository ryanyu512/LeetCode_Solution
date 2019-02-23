#include<iostream>
#include<vector>

class Solution {
public:
	int removeElement(std::vector<int>& nums, int val) {
		if (nums.empty())
			return 0;

		int length = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val) {
				length++;
				nums[length] = nums[i];
			}
		}


		return length + 1;
	}
};

int main() {

	std::vector<int> nums{ 0,1,2,2,3,0,4,2 };

	int val = 2;

	Solution sol;
	int len = sol.removeElement(nums, val);

	for (int i = 0; i < len; i++)
		std::cout << nums[i] << ' ';
	std::cout << std::endl;

	std::getchar(); std::getchar();
	return 0;
}