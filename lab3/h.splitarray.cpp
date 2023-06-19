#include <iostream>
#include <vector>


int main()
{
	long int n, k;
	std::cin >> n >> k;

	long int* arr = new long int[n];
	int* output = new int[n];

	long int sum = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		sum += arr[i];
		output[i] = 0;
	}

	long int left = 0;
	long int right = sum;
	long int mid = 0;
	long int current_sum = 0;
	long int k_current = 0;
	while (right - left > 1) {
		mid = (right + left) / 2;
		current_sum = 0;
		k_current = 1;
		for (long int j = 0; j < n; j++) {
			if (arr[j] > mid) {
				k_current = sum;
				break;
			}
			else if (current_sum + arr[j] > mid) {
				k_current++;
				current_sum = arr[j];
			}
			else {
				current_sum += arr[j];
			}
		}

		if (k_current > k) {
			left = mid;
		}
		else {
			right = mid;
		}
	}

	long int split_sum = right;
	current_sum = 0;

	long int counter = 0;

	for (long int i = 0; i < n; i++) {
		if (current_sum + arr[i] > split_sum) {
			current_sum = arr[i];
			output[i] = 1;
			counter++;
		}
		else { current_sum += arr[i]; }
	}

	for (long int i = 1; counter < k - 1; i++) {
		if (output[i] == 1) { continue; }
		output[i] = 1;
		counter++;
	}

	for (long int i = 0; i < n; i++) {
		if (output[i] == 1) {
			std::cout << i << ' ';
		}
	}
}
