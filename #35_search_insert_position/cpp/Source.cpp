#include<iostream>
#include<vector>

class Solution {

private:
	bool not_found;

	int BinarySearch(const std::vector<int> &num, const int target, const int left_bound, const int right_bound) {

		if (right_bound < left_bound){
			not_found = true;
			return -1;
		}

		int tar_idx;
		int idx = tar_idx = (left_bound + right_bound) / 2;

		if (num[idx] == target)
			return tar_idx;

		if (num[idx] > target)
			tar_idx = BinarySearch(num, target, left_bound, idx - 1);
		else if (num[idx] < target)
			tar_idx = BinarySearch(num, target, idx + 1, right_bound);

		tar_idx = (tar_idx == -1) ? idx : tar_idx;

		if (tar_idx < 0 || tar_idx >= num.size())
			return tar_idx;

		if (not_found && num[tar_idx] < target)
			tar_idx = idx + 1;

		return tar_idx;
	}

public:

	Solution() {
		not_found = false;
	}

	int searchInsert(std::vector<int>& nums, int target) {

		int idx = BinarySearch(nums, target, 0, nums.size() - 1);

		not_found = false;

		return idx;
	}
};

int main() {

	const int arr_size = 4;
	int num[arr_size] = { 1, 3, 5, 6 };
	std::vector<int> num_vec(arr_size);

	for (int i = 0; i < arr_size; i++)
		num_vec[i] = num[i];

	Solution sol;
	int tar_val = -1;
	int tar_idx = sol.searchInsert(num_vec, tar_val);
	
	for (int i = 0; i < arr_size; i++)
		std::cout << num_vec[i] << ' ';
	std::cout << tar_val << std::endl;
	std::cout << tar_idx << std::endl;


	std::getchar(); std::getchar();
	return 0;
}