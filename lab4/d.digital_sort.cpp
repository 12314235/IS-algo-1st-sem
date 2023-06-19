#include <iostream>
#include <vector>
#include <string>

void radix_sort(std::string* arr, int m, int n, int k) {
	int C[26];
	std::string* B = new std::string[n];
	int count;
	for (int i = m - 1; i > m - 1 - k; i--) {
		for (int j = 0; j < 26; j++) {
			C[j] = 0;
		}
		for (int j = 0; j < n; j++) {
			C[arr[j][i] - 'a']++;
		}
		count = 0;
		for (int j = 1; j < 26; j++) {
			C[j] += C[j - 1];
		}
		for (int j = n - 1; j >= 0; j--) {
			B[C[arr[j][i] - 'a'] - 1] = arr[j];
			C[arr[j][i] - 'a']--;
		}
		for (int i = 0; i < n; i++) {
			arr[i] = B[i];
		}
	}
}

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;

	std::string* arr = new std::string[n];

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	radix_sort(arr, m, n, k);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << '\n';
	}
}
