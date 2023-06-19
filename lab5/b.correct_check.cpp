#include <iostream>
#include <string>
#include <vector>

std::vector<long int> input_node;
std::vector<long int> left_number;
std::vector<long int> right_number;
bool is_validate = true;

void IsBinarySearchTree(long int i, long int min, long int max) {
	if (input_node.size() == 0) {
		return;
	}
	if (input_node[i] <= min || input_node[i] >= max) {
		is_validate = false;
		return;
	}
	if (left_number[i] != 0 && is_validate) {
		IsBinarySearchTree(left_number[i] - 1, min, input_node[i]);
	}
	if (right_number[i] != 0 && is_validate) {
		IsBinarySearchTree(right_number[i] - 1, input_node[i], max);
	}
}

int main() {
	long int N;

	std::cin >> N;

	std::string current_input;
	long int k, l, r;
	for (long int i = 0; i < N; i++) {
		std::cin >> k >> l >> r;
		input_node.push_back(k);
		left_number.push_back(l);
		right_number.push_back(r);
	}

	IsBinarySearchTree(0, -1e9 - 1, 1e9 + 1);

	std::cout << (is_validate ? "YES" : "NO");

	return 0;
}
