#include <iostream>
#include <vector>
#include <string>

std::vector<int> MergeSort(std::vector<int> array) {
    if (array.size() < 2) { return array; }
    else {
        std::vector<int> lower;
        std::vector<int> upper;
        int pivot = (array.size() - 1) / 2;
        if (pivot == 0) { pivot++; }
        for (int i = 0; i < pivot; i++) { lower.push_back(array[i]); }
        for (int i = pivot; i < array.size(); i++) { upper.push_back(array[i]); }

        lower = MergeSort(lower);
        upper = MergeSort(upper);

        int counter_lower = 0, counter_upper = 0;
        std::vector<int> result;
        while (counter_lower < lower.size() || counter_upper < upper.size()) {
            int x_up, x_low;
            if (counter_lower < lower.size()) { x_low = lower[counter_lower]; }
            else { x_low = INT_MAX; }
            if (counter_upper < upper.size()) { x_up = upper[counter_upper]; }
            else { x_up = INT_MAX; }
            if (x_low < x_up) {
                result.push_back(x_low);
                counter_lower++;
            }
            else {
                result.push_back(x_up);
                counter_upper++;
            }
        }

        return result;
    }
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> start;
	std::vector<int> end;

	for (int i = 0; i < n; i++) {
		int l, r;
		std::cin >> l;
		std::cin >> r;
		start.push_back(l);
		end.push_back(r);
	}

    start = MergeSort(start);
    end = MergeSort(end);

	int res = end[0] - start[0] + 1;
	for (int i = 1; i < n; i++) {
		if (start[i] <= end[i - 1]) { res += end[i] - end[i - 1]; }
		else { res += end[i] - start[i] + 1; }
	}

	std::cout << res;
}
