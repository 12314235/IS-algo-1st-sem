#include <iostream>
#include <string>


int main()
{
	int n;
	std::cin >> n;

	int* arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];
	}

	bool is_pyramid = true;

	for (int i = 1; i <= n && is_pyramid; i++) {
		if (2 * i <= n) {
			is_pyramid &= arr[i] <= arr[2 * i];
		}

		if (2 * i + 1 <= n) {
			is_pyramid &= arr[i] <= arr[2 * i + 1];
		}
	}

	std::string res = is_pyramid ? "YES" : "NO";

	std::cout << res;
}
