#include<string>
#include<iostream>

class Solution {
public:
	int lengthOfLastWord(std::string s) {

		if (s.empty())
			return 0;

		const char* c_ptr_s = s.c_str();

		int len = 0;
		for (int i = s.size() - 1; i >= 0; i --) {
			if (len == 0 && c_ptr_s[i] == ' ')
				continue;
			else if (len >= 0 && c_ptr_s[i] != ' ')
				len++;
			else if (len > 0 && c_ptr_s[i] == ' ')
				break;
		}

		return len;
	}
};

int main() {

	std::string s = "Hel lo ";

	Solution sol;
	int len = sol.lengthOfLastWord(s);

	std::cout << s << ": " << len << std::endl;

	std::getchar(); std::getchar();
	return 0;
}