#include <iostream>
#include <vector>
#include <string>

class PriorityQueue {
public:
	std::vector<std::pair<int, int>> queue;

	void shift_up(int i) {
		while (queue[i].first < queue[(i - 1) / 2].first) {
			std::swap(queue[i], queue[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	void shift_down(int i) {
		int left, right, j;
		while (2 * i + 1 < queue.size()){
			left = 2 * i + 1;
			right = 2 * i + 2;
			j = left;
			if (right < queue.size() && queue[right].first < queue[left].first) {
				j = right;
			}
			if (queue[i].first <= queue[j].first) {
				break;
			}
			std::swap(queue[i], queue[j]);
			i = j;
		}

	}

	void push(int x, int command_number) {
		queue.push_back(std::make_pair(x, command_number));
		shift_up(queue.size() - 1);
	}

	int extract_min() {
		int minimum = queue[0].first;
		queue[0] = queue[queue.size() - 1];
		queue.pop_back();
		shift_down(0);
		return minimum;
	}

	void decrease_key(int x, int y) {
		for (int i = 0; i < queue.size(); i++) {
			if (queue[i].second == x) {
				queue[i].first = y;
				shift_up(i);
				break;
			}
		}
	}

	int queue_size() {
		return queue.size();
	}
};

int main()
{
	std::string operation = "";
	int x, y;

	PriorityQueue queue;
	int command_counter = 0;

	std::vector<std::string> output;

	while (std::cin >> operation) {
		command_counter++;
		if (operation == "push") {
			std::cin >> x;
			queue.push(x, command_counter);
		} else if (operation == "extract-min") {

			if (queue.queue_size() == 0) {
				output.push_back("*");
			} else {
				output.push_back(std::to_string(queue.extract_min()));
			}

		} else if (operation == "decrease-key") {
			std::cin >> x >> y;
			queue.decrease_key(x, y);
		}
	}

	for (std::string i : output) {
		std::cout << i << '\n';
	}
}
