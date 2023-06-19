#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

	std::vector<int> arr;
	for (int i = 1; i <= n; i++)
	{
		arr.push_back(i);
	}

	for (int i = 2; i < n; i++) {
		std::swap(arr[i], arr[i / 2]);
	}

	for (int i : arr) {
		std::cout << i << ' ';
	}
}

