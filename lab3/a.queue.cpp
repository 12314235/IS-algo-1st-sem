#include <iostream>
#include <vector>

struct Node {
	int value;
	Node* next;

	Node(int x) {
		value = x;
		next = nullptr;
	}
};

struct Queue {
	Node* head = nullptr;
	Node* current = nullptr;

	void push(int x) {
		Node* buffer = new Node(x);

		if (head == nullptr) {
			head = buffer;
			current = buffer;
		}
		else {
			current->next = buffer;
			current = buffer;
		}
	}

	int pop() {
		Node* buffer = head;

		int x = head->value;
		head = head->next;

		if (head == nullptr) { current = nullptr; }

		delete(buffer);

		return x;
	}
};

int main() {
	Queue queue;
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
