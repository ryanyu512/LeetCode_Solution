#include<iostream>
#include<string>
#include<list>

class Solution {
public:
	int strStr(std::string haystack, std::string needle) {

		if (haystack.empty() && needle.empty() || !haystack.empty() && needle.empty())
			return 0;
		else if (haystack.empty() && !needle.empty())
			return -1;

		std::list<int> queue;
		for (int i = 0; i < haystack.size(); i++) {
			if (int(haystack[i] - needle[0]) == 0 && (haystack.size() - i) >= needle.size())
				queue.push_back(i);
		}

		std::list<int>::iterator itr = queue.begin();
		int first_idx = -1;
		for (; itr != queue.end(); ++itr) {
			bool is_found = true;
			for (int i = *itr, j = 0; i < *itr + needle.size(); i++) {
				if (int(haystack[i] - needle[j++]) != 0) {
					is_found = false;
					break;
				}
			}

			if (is_found) {
				first_idx = *itr;
				break;
			}
		}

		return first_idx;
	}
};

int main() {

	Solution sol;

	std::string haystack = "hello";
	std::string needle = "ll";

	int first_idx = sol.strStr(haystack, needle);

	std::cout << haystack << " " << needle << ": " << first_idx << std::endl;

	std::getchar(); std::getchar();
	return 0;
}