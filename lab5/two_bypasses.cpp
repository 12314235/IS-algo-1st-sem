#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<int> first_bypass;
int i;

struct Node {
	int value;
	Node* left;
	Node* right;

	Node(int val, Node* l, Node* r) {
		value = val;
		left = l;
		right = r;
	}
};

class BinarySearchTree {
public:
	Node* head = nullptr;

	Node* BuildTree(int min, int max) {
		if (i >= first_bypass.size()) {
			return nullptr;
		}

		Node* buff = nullptr;

		if (first_bypass[i] > min && first_bypass[i] < max) {
			buff = new Node(first_bypass[i], nullptr, nullptr);
			i++;
			if (i < first_bypass.size()) {
				buff->left = BuildTree(min, buff->value);
			}
			if (i < first_bypass.size()) {
				buff->right = BuildTree(buff->value, max);
			}
		}

		return buff;
	}

	void Show(Node* current) {
		if (current->left != nullptr)Show(current->left);
		if (current->right != nullptr)Show(current->right);
		std::cout << current->value << ' ';
	}
};

int main() {
	int N;
	std::cin >> N;

	int x;
	BinarySearchTree tree;

	for (int i = 0; i < N; i++) {
		std::cin >> x;
		first_bypass.push_back(x);
	}

	i = 0;

	tree.head = tree.BuildTree(0, N + 1);

	tree.Show(tree.head);
}
