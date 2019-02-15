#include<iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
private:

	ListNode *new_list_head;
	ListNode *new_list_tail;

	void InsertNode(const int val) {
		ListNode *new_node = new ListNode(val);
		if (new_list_head == NULL) {
			new_list_head = new_list_tail = new_node;
		}
		else {
			new_list_tail->next = new_node;
			new_list_tail = new_list_tail->next;
		}

		return;
	}

public:

	Solution() : new_list_head(NULL), new_list_tail(NULL) {};

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		while (l1 && l2) {
			if (l1->val < l2->val) {
				InsertNode(l1->val);
				l1 = l1->next;
			}
			else {
				InsertNode(l2->val);
				l2 = l2->next;
			}
		}

		if (l1 != NULL) {
			while (l1 != NULL) {
				InsertNode(l1->val);
				l1 = l1->next;
			}
		}
		else {
			while (l2 != NULL) {
				InsertNode(l2->val);
				l2 = l2->next;
			}
		}

		return new_list_head;
	}
};

int main() {

	ListNode *l1_tail = NULL;
	ListNode *l2_tail = NULL;

	ListNode *l1_head = NULL;
	ListNode *l2_head = NULL;

	int val1[] = { 1, 2, 4};
	int val2[] = { 1, 3, 4};
	
	for (int i = 0; i < 3; i++) {

		ListNode *cur_node1 = new ListNode(val1[i]);
		ListNode *cur_node2 = new ListNode(val2[i]);

		if (l1_head == NULL)
			l1_head = l1_tail = cur_node1;
		else{
			l1_tail->next = cur_node1;
			l1_tail = l1_tail->next;
		}
		if (l2_head == NULL)
			l2_head = l2_tail = cur_node2;
		else {
			l2_tail->next = cur_node2;
			l2_tail = l2_tail->next;
		}
	}

	Solution sol;
	ListNode *new_list_head = sol.mergeTwoLists(l1_head, l2_head);

	ListNode* cur_node = new_list_head;
	while (cur_node != NULL) {
		std::cout << cur_node->val << ' ';
		cur_node = cur_node->next;
	}

	std::getchar(); std::getchar();
	return 0;
}