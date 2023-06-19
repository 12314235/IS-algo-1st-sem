#include <iostream>
#include <string>
#include <vector>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node* parent;

	Node(int val, Node* l, Node* r, Node* par) {
		value = val;
		left = l;
		right = r;
		parent = par;
	}
};

class BinarySearchTree {
public:
	Node* head = nullptr;

	void Insert(int x) {
		if (Exists(x)) { return; }
		if (head == nullptr) {
			head = new Node(x, nullptr, nullptr, nullptr);
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
				current->left = new Node(x, nullptr, nullptr, current);
			}
			if (current->value < x && current->right == nullptr) {
				current->right = new Node(x, nullptr, nullptr, current);
			}
		}
	}

	Node* Search(int x) {
		Node* current = head;
		while (current != nullptr) {
			if (x == current->value) {
				return current;
			}
			else if (x > current->value) {
				current = current->right;
			}
			else {
				current = current->left;
			}
		}

		return current;
	}

	void Delete(int x) {
		Node* current = Search(x);

		if (current == nullptr) {
			return;
		}

		if (current->left == nullptr && current->right == nullptr) {
			if (current == head) {
				head = nullptr;
				return;
			}
			else if (current->parent->left == current) {
				current->parent->left = nullptr;
			}
			else if (current->parent->right == current) {
				current->parent->right = nullptr;
			}
		}

		else if (current->left == nullptr || current->right == nullptr) {
			if (current->left == nullptr) {
				if (current == head) {
					head = current->right;
				}
				else if (current->parent->left == current) {
					current->parent->left = current->right;
				}
				else {
					current->parent->right = current->right;
				}
				current->right->parent = current->parent;
			}
			else {
				if (current == head) {
					head = current->left;
				}
				else if (current->parent->left == current) {
					current->parent->left = current->left;
				}
				else {
					current->parent->right = current->left;
				}
				current->left->parent = current->parent;
			}
		}

		else {
			Node* successor = Next(current->value);
			current->value = successor->value;
			if (successor->parent->left == successor) {
				successor->parent->left = successor->right;
				if (successor->right != nullptr) {
					successor->right->parent = successor->parent;
				}
			}
			else {
				successor->parent->right = successor->right;
				if (successor->right != nullptr) {
					successor->right->parent = successor->parent;
				}
			}
		}
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

	Node* Next(int x) {
		Node* current = head;
		Node* successor = nullptr;
		while (current != nullptr) {
			if (current->value > x) {
				successor = current;
				current = current->left;
			}
			else {
				current = current->right;
			}
		}

		return successor;
	}

	Node* Prev(int x) {
		Node* current = head;
		Node* successor = nullptr;

		while (current != nullptr) {
			if (current->value >= x) {
				current = current->left;
			}
			else {
				successor = current;
				current = current->right;
			}
		}

		return successor;
	}
};

int main() {
	std::string operation;

	BinarySearchTree tree;
	Node* buffer;

	int x = 0;
	while (std::cin >> operation) {
		std::cin >> x;
		if (operation == "insert") {
			tree.Insert(x);
		}
		else if (operation == "delete") {
			tree.Delete(x);
		}
		else if (operation == "exists") {
			std::cout << (tree.Exists(x) ? "true" : "false") << '\n';
		}
		else if (operation == "next") {
			buffer = tree.Next(x);
			if (buffer == nullptr) {
				std::cout << "none" << '\n';
			}
			else {
				std::cout << buffer->value << '\n';
			}
		}
		else if (operation == "prev") {
			buffer = tree.Prev(x);
			if (buffer == nullptr) {
				std::cout << "none" << '\n';
			}
			else {
				std::cout << buffer->value << '\n';
			}
		}
	}

	return 0;
}
