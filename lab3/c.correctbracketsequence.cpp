#include <iostream>
#include <string>
#include <vector>

struct Node {
	char value;
	Node* head;

	Node(char x) {
		value = x;
		head = nullptr;
	}
};

struct Stack {
	Node* current = nullptr;
	int size = 0;

	void push(char x) {
		Node* buffer = new Node(x);

		if (current == nullptr) {
			current = buffer;
		}

		else {
			buffer->head = current;
			current = buffer;
		}

		size++;
	}

	char pop() {
		Node* buffer = current;

		char x = current->value;
		current = current->head;

		delete(buffer);

		size--;

		return x;
	}

	void clear() {
		while (current != nullptr) {
			Node* buff = current;
			current = current->head;
			delete(buff);
			size = 0;
		}
	}
};

int main()
{
	Stack stack;
	std::string input;
	std::vector<std::string> output;
	char current;
	bool f;


	while (std::cin >> input) {
		stack.clear();
		f = true;
		if (input.size() % 2 != 0) {
			output.push_back("NO");
			continue;
		}
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(' || input[i] == '[') { stack.push(input[i]); }

			else if (stack.size == 0) {
				f = false;
				break;
			}

			if (input[i] == ')') {
				if (!(stack.pop() == '(')) { 
					f = false;
					break;
				}
			}

			else if (input[i] == ']') {
				if (!(stack.pop() == '[')) {
					f = false;
					break;
				}
			}
		}
		if (stack.size != 0) {
			f = false;
		}
		output.push_back(f ? "YES" : "NO");
	}

	for (int i = 0; i < output.size(); i++) {
		std::cout << output[i] << '\n';
	}
}
