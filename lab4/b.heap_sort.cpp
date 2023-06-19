#include <iostream>
#include <string>

void shift_down(int* arr, int i, int n) {
	int j = i;
	int left_son = 2 * i + 1;
	int right_son = 2 * i + 2;
	if (left_son < n && arr[left_son] > arr[j]) { j = left_son; }
	if (right_son < n && arr[right_son] > arr[j]) { j = right_son; }
	if (j != i) {
		std::swap(arr[i], arr[j]);
		shift_down(arr, j, n);
	}
}

void build_heap(int* arr, int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		shift_down(arr, i, n);
	}
}

void heap_sort(int* arr, int n) {
	build_heap(arr, n);
	for (int i = n - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		shift_down(arr, 0, i);
	}
}

int main()
{
	int n;
	std::cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	heap_sort(arr, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
}
