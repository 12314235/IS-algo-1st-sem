#include <iostream>
#include <string>
#include <vector>

int N;

class SegTree {
public:
	std::vector<int> tree;

	void show_tree() {
		for (int i = 0; i < N * 2; i++) {
			std::cout << tree[i] << ' ';
		}
	}

	void fill_parents() {
		for (int i = N; i > 0; i--) {
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}
	}

	void fix_parents(int i) {
		i /= 2;
		while (i != 0) {
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
			i /= 2;
		}
	}

	void change_leave(int i, int value, char operation) {
		switch (operation) {
		case '+':
			tree[i + N] += value;
			break;
		case '-':
			tree[i + N] = (value >= tree[i + N]) ? 0 : tree[i + N] - value;
			break;
		}

		fix_parents(i + N);
	}

	int sum(int left, int right) {
		int res = 0;
		while (left <= right) {
			if (left % 2 != 0) {
				res += tree[left];
			}
			if (right % 2 == 0) {
				res += tree[right];
			}

			left = (left + 1) / 2;
			right = (right - 1) / 2;
		}

		return res;
	}
};

int main() {
	srand(time(0));
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int Q;

	std::cin >> N >> Q;

	SegTree tree;

	for (int i = 0; i <= 2 * N + 1; i++) {
		tree.tree.push_back(0);
	}

	char operation;
	int x, y;

	tree.fill_parents();

	for (int i = 0; i < Q; i++) {
		std::cin >> operation >> x >> y;
		switch (operation) {
		case '?':
			std::cout << tree.sum(x + N, y + N) << '\n';
			break;
		default:
			tree.change_leave(x, y, operation);
			break;
		}
	}

	return 0;
}
