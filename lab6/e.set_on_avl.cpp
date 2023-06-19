#include <iostream>
#include <string>
#include <vector>

int line = 1;

struct Node {
	int value;
	Node* left;
	Node* right;
	int height;

	Node(int value, Node* left, Node* right, int height) {
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
		return current ? height(current->right) - height(current->left) : 0;
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

	Node* Insert(int x, Node* current) {
		if (Exists(x)) {
			return head;
		}
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

	Node* find_max(Node* current) {
		return current->right ? find_max(current->right) : current;
	}

	Node* remove_max(Node* current) {
		if (current->right == nullptr) {
			return current->left;
		}
		current->right = remove_max(current->right);

		return balance(current);
	}

	Node* remove(Node* current, int x) {
		if (current == nullptr) {
			return nullptr;
		}
		if (x < current->value) {
			current->left = remove(current->left, x);
		}
		else if (x > current->value) {
			current->right = remove(current->right, x);
		}
		else {
			Node* left = current->left;
			Node* right = current->right;
			delete current;
			if (left == nullptr) {
				return right;
			}
			Node* max = find_max(left);
			max->left = remove_max(left);
			max->right = right;
			return balance(max);
		}
		return balance(current);
	}

	bool Exists(int x) {
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
	srand(time(0));
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	char operation;
	int x;

	Tree tree;

	for (int i = 0; i < N; i++) {
		std::cin >> operation >> x;
		switch (operation) {
		case 'A':
			tree.head = tree.Insert(x, tree.head);
			std::cout << tree.balance_factor(tree.head) << '\n';
			break;
		case 'D':
			tree.head = tree.remove(tree.head, x);
			std::cout << tree.balance_factor(tree.head) << '\n';
			break;
		case 'C':
			std::cout << (tree.Exists(x) ? 'Y' : 'N') << '\n';
		}
	}

	return 0;
}
