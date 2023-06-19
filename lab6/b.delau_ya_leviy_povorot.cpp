#include <iostream>
#include <string>
#include <vector>

int line = 1;

struct Node {
    int value;
    int left;
    int right;
    int height;
    int line_number;

    Node(int value, int left, int right, int height) {
        this->value = value;
        this->left = left;
        this->right = right;
        this->height = height;
    }
};

class Tree {
public:

    std::vector<Node*> tree;

    void push(int value, int left, int right, int height) {
        Node* new_node = new Node(value, left, right, height);
        tree.push_back(new_node);
    }

    int calculate_height(int current, int current_height) {
        if (current < 0) {
            return 0;
        }

        tree[current]->height = std::max(calculate_height(tree[current]->left,
            current_height), calculate_height(tree[current]->right, current_height)) + 1;
        return tree[current]->height;
    }

    int height(int current) {
        return (current == -1) ? 0 : tree[current]->height;
    }

    void fix(int current) {
        tree[current]->height = std::max(height(tree[current]->left), height(tree[current]->right)) + 1;
    }

    int rotate_left(int current) {
        int buff = tree[current]->right;
        tree[current]->right = tree[buff]->left;
        tree[buff]->left = current;
        fix(current);
        fix(buff);

        return buff;
    }

    int rotate_right(int current) {
        int buff = tree[current]->left;
        tree[current]->left = tree[buff]->right;
        tree[buff]->right = current;
        fix(current);
        fix(buff);

        return buff;
    }

    int big_left_rotation(int current) {
        tree[current]->right = rotate_right(tree[current]->right);

        return rotate_left(current);
    }

    int balance(int current) {
        int right = tree[current]->right;

        if (right >= 0) {
            if (height(tree[right]->right) - height(tree[right]->left) < 0) {
                return big_left_rotation(current);
            }
        }

        return rotate_left(current);
    }

    void Smth(int current) {
        if (current < 0) { return; }
        tree[current]->line_number = line;
        line++;
        Smth(tree[current]->left);
        Smth(tree[current]->right);
    }

    void pre_order_bypass(int head) {
        if (head < 0) { return; }
        std::cout << tree[head]->value << ' ';
        if (tree[head]->left != -1) {
            std::cout << tree[tree[head]->left]->line_number;
        }
        else {
            std::cout << 0;
        }
        std::cout << ' ';
        if (tree[head]->right != -1) {
            std::cout << tree[tree[head]->right]->line_number;
        }
        else {
            std::cout << 0;
        }
        std::cout << '\n';
        if (tree[head]->left != -1) {
            pre_order_bypass(tree[head]->left);
        }
        if (tree[head]->right != -1) {
            pre_order_bypass(tree[head]->right);
        }
    }
};

int main() {
    int N;
    std::cin >> N;

    int k, l, r;

    Tree tree;

    for (int i = 0; i < N; i++) {
        std::cin >> k >> l >> r;
        tree.push(k, l - 1, r - 1, 0);
    }

    if (N == 0) {
        std::cout << 0 << '\n';
        return 0;
    }

    tree.calculate_height(0, 0);

    int head = tree.balance(0);

    std::cout << N << '\n';
    tree.Smth(head);
    tree.pre_order_bypass(head);

    return 0;
}
