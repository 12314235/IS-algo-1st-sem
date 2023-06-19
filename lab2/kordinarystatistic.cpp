#include <iostream>
#include <vector>

void QuickSort(int* array, int left, int right, int k) {
    int pivot = array[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (array[i] < pivot) { i++; }
        while (pivot < array[j]) { j--; }

        if (i <= j) {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }

    }
    if (j < k && k < i) { return; }

    if (left < j && k <= j) { QuickSort(array, left, j, k); }

	if (i < right && k >= i) { QuickSort(array, i, right, k); }
}

int main() {
	int n, k, A, B, C, a1, a2;
	std::cin >> n;
	std::cin >> k;
	std::cin >> A;
	std::cin >> B;
	std::cin >> C;
	std::cin >> a1;
	std::cin >> a2;
	int* order_statistic = new int[n];
	order_statistic[0] = a1;
	order_statistic[1] = a2;
	int i = 2;
	while (i < n) {
		order_statistic[i] = A* order_statistic[i - 2] + B * order_statistic[i - 1] + C;
		i++;
	}

    QuickSort(order_statistic, 0, n - 1, k - 1);
    std::cout << order_statistic[k - 1];
}
