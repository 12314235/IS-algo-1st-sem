#include <iostream>
#include <vector>

int HEIGHT = 0;
std::vector<int> input_node;
std::vector<int> left_number;
std::vector<int> right_number;
std::vector<int> heights;

void HeightSearch(int i) {
	if (i == -1) return;
	heights[i] = 1 + std::max(left_number[i] >= 0 ? heights[left_number[i]] : 0, right_number[i] >= 0 ? heights[right_number[i]] : 0);
	HeightSearch(i - 1);
}

int main() {
	int N;

	std::cin >> N;

	int k, l, r;
	for (int i = 0; i < N; i++) {
		std::cin >> k >> l >> r;
		heights.push_back(0);
		input_node.push_back(k - 1);
		left_number.push_back(l - 1);
		right_number.push_back(r - 1);
	}

	HeightSearch(N - 1);

	for (int i = 0; i < N; i++) {
		std::cout << (right_number[i] >= 0 ? heights[right_number[i]] : 0) - (left_number[i] >= 0 ? heights[left_number[i]] : 0) << '\n';
	}

	return 0;
}
