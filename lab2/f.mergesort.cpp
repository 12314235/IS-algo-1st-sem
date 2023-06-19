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

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr;
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        arr.push_back(k);
    }
    arr = MergeSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
}

