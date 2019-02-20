#include<iostream>
#include<string>
#include<list>

class Solution {
public:

	std::list<char> stack;

	bool isValid(std::string s) {

		if (s.empty())
			return true;

		if (s.size() % 2 != 0)
			return false;

		bool is_valid = true;

		const char* c_ptr = s.c_str();

		for (int i = 0; i < s.size(); i++) {

			if (c_ptr[i] == '{' || c_ptr[i] == '[' || c_ptr[i] == '(')
				stack.push_front(c_ptr[i]);
			else{

				if (stack.empty()) {
					is_valid = false;
					break;
				}

				if ((stack.front() == '{' && c_ptr[i] == '}') ||
					(stack.front() == '[' && c_ptr[i] == ']') ||
					(stack.front() == '(' && c_ptr[i] == ')'))
					stack.pop_front();
				else {
					is_valid = false;
					break;
				}
			}
		}

		if (!stack.empty()){
			stack.clear();
			return false;
		}

		return is_valid;
	}
};

int main() {
	
	Solution sol;

	std::string s = "((";

	bool is_valid = sol.isValid(s);

	std::cout << is_valid << std::endl;

	std::getchar(); std::getchar();
	return 0;
}