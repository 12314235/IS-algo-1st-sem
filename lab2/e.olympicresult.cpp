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

std::vector<int> SortGrade(std::vector<int> mask, std::vector<int> grade) {
    if (mask.size() < 2) { return mask; }
    else {
        std::vector<int> upper;
        std::vector<int> lower;
        int pivot = grade[mask[0]];
        for (int i = 1; i < mask.size(); i++) {
            if (grade[mask[i]] <= pivot) { lower.push_back(mask[i]); }
            else { upper.push_back(mask[i]); }
        }
        return Concat(SortGrade(upper, grade), mask[0], SortGrade(lower, grade));
    }
}

std::vector<int> SortId(std::vector<int> mask, std::vector<int> id, std::vector<int> grade) {
    for (int i = 1; i < mask.size(); i++) {
        int j = i;
        while (grade[mask[j]] == grade[mask[j - 1]] && id[mask[j]] < id[mask[j - 1]]) {
            std::swap(mask[j], mask[j - 1]);
            j--;
            if (j == 0) break;
        }
    }

    return mask;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> id;
    std::vector<int> grade;
    std::vector<int> mask;

    for (int i = 0; i < n; i++) {
        int buffer_id, buffer_grade;
        std::cin >> buffer_id;
        std::cin >> buffer_grade;
        grade.push_back(buffer_grade);
        id.push_back(buffer_id);
        mask.push_back(i);
    }

    mask = SortGrade(mask, grade);
    mask = SortId(mask, id, grade);

    for (int i = 0; i < mask.size(); i++) {
        std::cout << id[mask[i]] << ' ' << grade[mask[i]] << '\n';
    }

}

