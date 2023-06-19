#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main()
{
	int n;
	double A;
	std::cin >> n >> A;

	double left = A;
	double right = 0;
	double middle;
	double current;
	double next;
	double previos;
	double result = 0;

	bool is_above_ground;

	while (left - right > static_cast<double>(1e-9)) {
		middle = (left + right) / 2;
		current = middle;
		previos = A;
		is_above_ground = current > 0;
		for (int i = 2; i < n; i++) {
			next = 2 * (current + 1) - previos;
			is_above_ground = is_above_ground && (next > 0);
			previos = current;
			current = next;
		}

		if (is_above_ground) {
			left = middle;
			result = current;
		}
		else {
			right = middle;
		}
	}

	std::cout << std::fixed << std::setprecision(2) << result;
}
