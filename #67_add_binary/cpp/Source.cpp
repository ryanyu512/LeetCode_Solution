#include<iostream>
#include<string>

class Solution {
public:
	std::string addBinary(std::string a, std::string b) {

		if (a.empty())
			return b;
		if (b.empty())
			return a;

		std::string sum;
		int i = a.size() - 1, j = b.size() - 1;
		short temp = 0;
		while(i >= 0 || j >= 0 || temp > 0) {
			temp += ((i >= 0)? a[i--] - '0':0) + ((j >= 0)? b[j--] - '0':0);
			sum += (temp%2) + '0';
			temp /= 2;
		}
						
		std::reverse(sum.begin(), sum.end());

		return sum;
	}
};

int main() {

	Solution sol;
	std::string s1 = "11", s2 = "1";
	std::string result = sol.addBinary(s1, s2);

	std::cout << s1 << "+" << s2 << "=" << result;

	std::getchar(); std::getchar();
	return 0;
}