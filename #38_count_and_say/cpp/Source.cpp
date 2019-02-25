#include<iostream>
#include<string>
#include<sstream>
#include<list>

class Solution {

public:
	std::string countAndSay(int n) {
		std::string str = "1";
		for (int i = 0; i < n - 1; i++) {
			int num = 0;
			std::string temp = "";
			for (int j = 0; j < str.size(); j++) {
				if (j == 0 || str[j] == str[j - 1])
					num++;
				else {
					temp += num + '0';
					temp += str.substr(j - 1, 1);
					num = 1;
				}

				if (j == str.size() - 1) {
					temp += num + '0';
					temp += str.substr(j, 1);
				}
			}
			str = temp;
		}

		return str;
	}
};

int main() {

	Solution sol;
	std::string result = sol.countAndSay(10);

	std::cout << result << std::endl;

	std::getchar(); std::getchar();
	return 0;
}