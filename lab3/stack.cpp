#include <iostream>
#include <vector>

struct Node {
	int value;
	Node* head;

	Node(int x) {
		value = x;
		head = nullptr;
	}
};

struct Stack {
	Node* current = nullptr;

	void push(int x) {
		Node* buffer = new Node(x);

		if (current == nullptr) {
			current = buffer;
		}

		else {
			buffer->head = current;
			current = buffer;
		}
	}

	int pop() {
		Node* buffer = current;

		int x = current->value;
		current = current->head;

		delete(buffer);

		return x;
	}
};

int main() {
	Stack queue;
	int n;
	std::cin >> n;
	char operation;

	std::vector<int> output;
	int x = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> operation;
		if (operation == '+') {
			std::cin >> x;
			queue.push(x);
		}
		else {
			output.push_back(queue.pop());
		}
	}

	for (int i : output) {
		std::cout << i << '\n';
	}
}
