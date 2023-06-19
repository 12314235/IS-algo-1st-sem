#include <iostream>
#include <string>
#include <vector>

struct Node {
	int value;
	int max = -1;
	Node* head;

	Node(int x, int init_max) {
		value = x;
		max = init_max;
		head = nullptr;
	}
};

struct Stack {
	Node* current = nullptr;

	void push(int x) {
		Node* buffer = new Node(x, x);

		if (current == nullptr) {
			current = buffer;
		}

		else {
			buffer->head = current;
			buffer->max = std::max(x, current->max);
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

	int current_max() {
		return current->max;
	}
};

int main()
{
	Stack stack;

	int n;
	std::cin >> n;

	std::string operation;
	std::vector<int> output;
	int x;

	for (int i = 0; i < n; i++) {
		std::cin >> operation;

		if (operation == "+") {
			std::cin >> x;
			stack.push(x);
		}
		else if (operation == "-") {
			stack.pop();
		}
		else if (operation == "max") {
			output.push_back(stack.current_max());
		}
	}

	for (int i : output) {
		std::cout << i << '\n';
	}
}
