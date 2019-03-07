#include<iostream>
#include<vector>
class Solution {

public:
	int climbStairs(int n) {
		if (n <= 2)
			return n;

		int prev = 1, cur = 2;

		for (int i = 3; i <= n; i++) {
			int temp = cur + prev;
			prev = cur;
			cur = temp;
		}

		return cur;
	}
};



int main() {

	Solution sol;
	std::cout << sol.climbStairs(5) << std::endl;

	std::getchar(); std::getchar();
	return 0;
}