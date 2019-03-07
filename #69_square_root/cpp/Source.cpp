#include<iostream>

class Solution {

private:

	float BinarySearch(double tar_val, double start_val, double end_val) {

		if (start_val >= end_val){
			if(std::pow(start_val, 2) > tar_val)
				return start_val - 1;
			else
				return start_val;
		}

		double mid_val = std::floor((start_val + end_val) / 2.f);

		double est_val = std::pow(mid_val, 2);

		if (est_val == tar_val)
			return mid_val;

		if (est_val > tar_val)
			return BinarySearch(tar_val, start_val, mid_val - 1);
		else
			return BinarySearch(tar_val, mid_val + 1, end_val);
	}

public:
	int mySqrt(int x) {
		return std::floor(BinarySearch(x, 0, x));
	}
};

int main() {

	Solution sol;
	int test_val = 2147395599;
	int result = sol.mySqrt(test_val);
	int ground_truth = std::floor(sqrt(float(test_val)));
	std::cout << result << ": " << result*result << std::endl;
	std::cout << ground_truth << ": " << ground_truth*ground_truth << std::endl;
	std::getchar(); std::getchar();
	return 0;
}