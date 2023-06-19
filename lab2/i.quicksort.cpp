#include <iostream>
#include <vector>
#include <string>

std::vector<int> Concat(std::vector<int> lower, int pivot, std::vector<int> upper) {
    lower.push_back(pivot);
    for (int i = 0; i < upper.size(); i++) {
        lower.push_back(upper[i]);
    }
    return lower;
}

std::vector<int> QuickSort(std::vector<int> arr) {
    if (arr.size() < 2) { return arr; }
    else {
        std::vector<int> lower;
        std::vector<int> upper;
        int pivot = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= pivot) { upper.push_back(arr[i]); }
            else { lower.push_back(arr[i]); }
        }
        return Concat(QuickSort(lower), pivot, QuickSort(upper));
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr1;
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        arr1.push_back(k);
    }

    arr1 = QuickSort(arr1);

    for (int i : arr1) {
        std::cout << i << ' ';
    }
}
