#include <iostream>

int BinarySearchFirstIn(int* array, int x, int n) {
	int left = -1;
	int right = n;
	while (right > left + 1) {
		int pivot = (left + right) / 2;
		if (array[pivot] < x) { left = pivot; }
		else { right = pivot; }
	}

	if (right < n && array[right] == x) { return right;	}

	else { return -1; }
}

int BinarySearchLastIn(int* array, int x, int n) {
	int left = -1;
	int right = n;
	while (right > left + 1) {
		int pivot = (left + right) / 2;
		if (array[pivot] <= x) { left = pivot; }
		else { right = pivot; }
	}

	if (left < n && array[left] == x) { return left; }

	else { return -1; }
}

int main()
{
	int n;
	std::cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> array[i];
	}

	int count;
	std::cin >> count;
	int x;
	int first_in;
	int last_in;

	for (int i = 0; i < count; i++) {
		std::cin >> x;
		first_in = BinarySearchFirstIn(array, x, n);

		if (first_in == -1) { 
			std::cout << "-1 -1" << '\n';
		}
		else {
			last_in = BinarySearchLastIn(array, x, n);
			std::cout << first_in + 1 << ' ' << last_in + 1 << '\n';
		}
	}
}
