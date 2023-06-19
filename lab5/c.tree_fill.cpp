#include <iostream>
#include <string>
#include <vector>

std::vector<int> left_number;
std::vector<int> right_number;
std::vector<int> result;
int current;
bool f = true;

void Smth(int i) {
	if (current == 0) {
		return;
	}
	else {
		if (right_number[i] != 0) {
			Smth(right_number[i] - 1);
		}
		if (result[i] == 0) {
			result[i] = current;
			current--;
		}
		if (left_number[i] != 0) {
			Smth(left_number[i] - 1);
			if (result[i] == 0) {
				result[i] = current;
				current--;
			}
		}
	}
}

int main() {
	int N;

	std::cin >> N;

	int k, l, r;
	for (int i = 0; i < N; i++) {
		std::cin >> l >> r;
		left_number.push_back(l);
		right_number.push_back(r);
		result.push_back(0);
	}

	current = N;

	Smth(0);

	for (int i : result) {
		std::cout << i << ' ';
	}

	return 0;
}
