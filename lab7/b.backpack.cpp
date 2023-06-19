#include <iostream>
#include <string>

int main() {
    int S, N;

    std::cin >> S >> N;
    int* p = new int[N + 1];

    for (int i = 1; i <= N; i++) {
        std::cin >> p[i];
    }

    int** A = new int*[N + 1];

    for (int i = 0; i <= N; i++) {
        A[i] = new int[S+1];
    }

    for (int i = 0; i <= S; i++) {
        A[0][i] = 0;
    }

    for (int i = 0; i <= N; i++) {
        A[i][0] = 0;
    }

    for (int k = 1; k <= N; k++) {
        for (int j = 1; j <= S; j++) {
            if (j >= p[k]) {
                A[k][j] = std::max(A[k - 1][j], A[k - 1][j - p[k]] + p[k]);
            }
            else {
                A[k][j] = A[k - 1][j];
            }
        }
    }

    std::cout << A[N][S];
}
