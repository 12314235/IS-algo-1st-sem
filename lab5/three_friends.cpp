#include <iostream>
#include <vector>
#include <string>


struct Node {
	std::string value;
	Node* left;
	Node* right;

	Node(std::string val, Node* l, Node* r) {
		value = val;
		left = l;
		right = r;
	}
};

class BinarySearchTree {
public:
	Node* head = nullptr;

	void Insert(std::string x) {
		if (Exists(x)) { return; }
		if (head == nullptr) {
			head = new Node(x, nullptr, nullptr);
		}
		else {
			Node* current = head;
			while (!((current->value > x && current->left == nullptr) || (current->value < x && current->right == nullptr))) {
				if (current->value > x) {
					current = current->left;
				}
				else {
					current = current->right;
				}
			}
			if (current->value > x && current->left == nullptr) {
				current->left = new Node(x, nullptr, nullptr);
			}
			if (current->value < x && current->right == nullptr) {
				current->right = new Node(x, nullptr, nullptr);
			}
		}
	}

	bool Exists(std::string x) {
		if (head == nullptr) {
			return false;
		}
		else {
			Node* current = head;
			while (!((current->value > x && current->left == nullptr) || (current->value < x && current->right == nullptr))) {
				if (current->value == x) {
					return true;
				}
				else if (current->value > x) {
					current = current->left;
				}
				else {
					current = current->right;
				}
			}

			return false;
		}
	}
};

int main() {
	int N;
	std::cin >> N;

	std::string inp;
	int val;

	BinarySearchTree tree1;
	BinarySearchTree tree2;
	BinarySearchTree tree3;

	std::string* first = new std::string[N];
	std::string* second = new std::string[N];

	for (int i = 0; i < N; i++) {
		std::cin >> inp;
		tree1.Insert(inp);
		first[i] = inp;
	}

	for (int i = 0; i < N; i++) {
		std::cin >> inp;
		tree2.Insert(inp);
		second[i] = inp;
	}

	for (int i = 0; i < N; i++) {
		std::cin >> inp;
		tree3.Insert(inp);
	}

	int score1 = 3 * N;
	int score2 = 3 * N;
	int score3 = 3 * N;

	bool f1, f2, f3;

	for (int i = 0; i < N; i++) {
		f1 = tree2.Exists(first[i]);
		f2 = tree3.Exists(first[i]);
		f3 = tree3.Exists(second[i]) && !tree1.Exists(second[i]);
		if (f1 && f2) {
			score1 -= 3;
			score2 -= 3;
			score3 -= 3;
		}
		else if (f1) {
			score1 -= 2;
			score2 -= 2;
		}
		else if (f2) {
			score1 -= 2;
			score3 -= 2;
		}
		if (f3) {
			score2 -= 2;
			score3 -= 2;
		}
	}

	std::cout << score1 << ' ' << score2 << ' ' << score3;

	return 0;
}
