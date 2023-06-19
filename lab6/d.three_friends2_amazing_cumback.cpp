#include <iostream>
#include <string>
#include <vector>

int line = 1;

struct Node {
	std::string value;
	Node* left;
	Node* right;
	int height;

	Node(const std::string& value, Node* left, Node* right, int height) {
		this->value = value;
		this->left = left;
		this->right = right;
		this->height = height;
	}
};

class Tree {
public:
	Node* head = nullptr;

	int height(Node* current) {
		return current ? current->height : 0;
	}

	int balance_factor(Node* current) {
		return height(current->right) - height(current->left);
	}

	void fix(Node* current) {
		current->height = std::max(height(current->left), height(current->right)) + 1;
	}

	Node* rotate_left(Node* current) {
		Node* buff = current->right;
		current->right = buff->left;
		buff->left = current;
		fix(current);
		fix(buff);

		return buff;
	}

	Node* rotate_right(Node* current) {
		Node* buff = current->left;
		current->left = buff->right;
		buff->right = current;
		fix(current);
		fix(buff);

		return buff;
	}

	Node* balance(Node* current) {
		fix(current);
		if (balance_factor(current) == 2) {
			if (balance_factor(current->right) < 0) {
				current->right = rotate_right(current->right);
			}
			return rotate_left(current);
		}
		if (balance_factor(current) == -2) {
			if (balance_factor(current->left) > 0) {
				current->left = rotate_left(current->left);
			}
			return rotate_right(current);
		}
		return current;
	}

	Node* Insert(const std::string& x, Node* current) {
		if (current == nullptr) {
			return new Node(x, nullptr, nullptr, 1);
		}
		else {
			if (x < current->value) {
				current->left = Insert(x, current->left);
			}
			else {
				current->right = Insert(x, current->right);
			}
			return balance(current);
		}
	}

	bool Exists(const std::string& x) {
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

	Tree tree1;
	Tree tree2;
	Tree tree3;

	std::string* first = new std::string[N];
	std::string* second = new std::string[N];

	for (int i = 0; i < N; i++) {
		std::cin >> inp;
		tree1.head = tree1.Insert(inp, tree1.head);
		first[i] = inp;
	}

	for (int i = 0; i < N; i++) {
		std::cin >> inp;
		tree2.head = tree2.Insert(inp, tree2.head);
		second[i] = inp;
	}

	for (int i = 0; i < N; i++) {
		std::cin >> inp;
		tree3.head = tree3.Insert(inp, tree3.head);
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
