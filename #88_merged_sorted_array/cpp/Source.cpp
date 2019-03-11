#include<iostream>
#include<vector>
#include<time.h>

class Solution {

public:
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		if (n == 0)
			return;

		std::vector<int> nums(m + n, 0);

		int i = 0, j = 0, k = 0;
		while (i < m && j < n) {
			if (nums1[i] < nums2[j])
				nums[k++] = nums1[i++];
			else
				nums[k++] = nums2[j++];
		}

		while (i < m) {
			nums[k++] = nums1[i++];
		}
		while (j < n) {
			nums[k++] = nums2[j++];
		}

		for (int i = 0; i < nums.size(); i++)
			nums1[i] = nums[i];
	}
};

int main() {

	clock_t t1, t2;

	std::vector<int> nums1{ 1,2,3,0,0,0 };
	std::vector<int> nums2{ 2,5,6 };

	t1 = clock();
	Solution sol;
	sol.merge(nums1, 3, nums2, 3);
	t2 = clock();

	for (int i = 0; i < nums1.size(); i++) {
		std::cout << nums1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << (t2 - t1) / (double)(CLOCKS_PER_SEC) << std::endl;

	std::getchar(); std::getchar();
	return 0;
}