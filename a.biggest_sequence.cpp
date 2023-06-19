#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;

    std::cin >> N;

    int* a = new int[N];

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    int* prev = new int[N];
    int* d = new int[N];

    for (int i = 0; i < N; i++) {
        d[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[j] + 1 > d[i]) {
                d[i]++;
                prev[i] = j;
            }
        }
    }

    int pos = 0;
    int length = d[0];

    for (int i = 0; i < N; i++) {
        if (d[i] > length) {
            pos = i;
            length = d[i];
        }
    }

    std::vector<int> answer;
    while (pos != -1) {
        answer.push_back(a[pos]);
        pos = prev[pos];
    }

    std::cout << answer.size() << '\n';

    for (int i = answer.size() - 1; i >= 0; i--) {
        std::cout << answer[i] << ' ';
    }
}
