#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {

		if (strs.empty())
			return "";

		int shortest_str_idx = 0;
		int shortest_str_len = INT_MIN;
		for (int i = 0; i < strs.size(); i++) {
			if (shortest_str_len > strs[i].size()) {
				shortest_str_idx = i;
				shortest_str_len = strs[i].size();
			}
		}

		std::vector<bool> is_same_char(strs[shortest_str_idx].size(), true);
		int same_letter_length = 0;
		for (int i = 0; i < strs[shortest_str_idx].size(); i++) {
			for (int j = 0; j < strs.size(); j++) {
				if (strs[j][i] != strs[shortest_str_idx][i]) {
					is_same_char[i] = false;
					break;
				}
			}

			same_letter_length = (is_same_char[i]) ? same_letter_length + 1 : same_letter_length;
		}

		if (same_letter_length == 0)
			return "";

		std::string longest_common_prefix;
		for (int i = 0; i < strs[shortest_str_idx].size(); i++) {
			if (is_same_char[i])
				longest_common_prefix.append(strs[shortest_str_idx], i, 1);
			else
				break;
		}

		return longest_common_prefix;
	}
};

int main() {

	std::vector<std::string> strs(3);
	strs[0] = "flower";
	strs[1] = "flow";
	strs[2] = "flight";

	Solution sol;
	std::string longest_common_prefix = sol.longestCommonPrefix(strs);

	std::cout << longest_common_prefix << std::endl;

	std::getchar(); std::getchar();
	return 0;
}