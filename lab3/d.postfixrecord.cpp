#include <iostream>
#include <string>
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

int Convert(std::string buffer) {
	int value = 0;

	for (char i : buffer) {
		value = value * 10 + static_cast<int>(i - '0');
	}

	return value;
}

int main()
{
	Stack stack;

	std::string input;
	std::getline(std::cin, input);

	std::string buffer;

	int a, b;

	for (int i = 0; i < input.size(); i++) {
		if ('0' <= input[i] && input[i] <= '9') {
			buffer = "";
			buffer += input[i];
			i++;
			while (input[i] != ' ' && i != input.size()) {
				buffer += input[i];
				i++;
			}

			stack.push(Convert(buffer));
		}

		else if (input[i] != ' ') {
			a = stack.pop();
			b = stack.pop();

			switch (input[i]) {
			case '+':
				stack.push(a + b);
				break;
			case '-':
				stack.push(b - a);
				break;
			case '*':
				stack.push(a * b);
				break;
			}
		}
	}

	std::cout << stack.pop();
}
