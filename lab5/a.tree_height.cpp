#include <iostream>
#include <string>
#include <vector>

int HEIGHT = 0;
std::vector<int> input_node;
std::vector<int> left_number;
std::vector<int> right_number;

void HeightSearch(int i, int current_height) {
	HEIGHT = std::max(current_height, HEIGHT);
	if (left_number.size() == 0) {
		return;
	}
	if (left_number[i] > 0) {
		HeightSearch(left_number[i] - 1, current_height + 1);
	}
	if (right_number[i] > 0) {
		HeightSearch(right_number[i] - 1, current_height + 1);
	}
}

int main() {
	int N;

	std::cin >> N;

	std::string current_input;
	int k, l, r;
	for (int i = 0; i < N; i++) {
		std::cin >> k >> l >> r;
		input_node.push_back(k);
		left_number.push_back(l);
		right_number.push_back(r);
	}

	HeightSearch(0, 1);

	std::cout << ((input_node.size() > 0) ? HEIGHT : 0);

	return 0;
}
