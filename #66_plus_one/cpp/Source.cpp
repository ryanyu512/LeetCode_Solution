#include<iostream>
#include<vector>

class Solution {
public:
	std::vector<int> plusOne(std::vector<int>& digits) {

		if (digits.empty())
			return digits;

		*(digits.rbegin()) += 1;
		if (*(digits.rbegin()) == 10)
			*(digits.rbegin()) = 0;

		for (int i = digits.size() - 2; i >= 0; i--) {

			if (digits[i + 1] == 0){
				digits[i] += 1;
				digits[i] = (digits[i] == 10)? 0:digits[i];
			}
			else 
				break;
		}
		
		if (digits[0] == 0)
			digits.insert(digits.begin(), 1);

		return digits;
	}
};

int main() {

	std::vector<int> vec{ 9, 9 };

	Solution sol;

	std::vector<int> result = sol.plusOne(vec);

	for (int i = 0; i < result.size(); i ++)
		std::cout << result[i];

	std::getchar(); std::getchar();
	return 0;
}