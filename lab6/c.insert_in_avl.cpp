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

    int head = -1;

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

    int balance_factor(int current) {
        return height(tree[current]->right) - height(tree[current]->left);
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

    int balance(int current) {
        fix(current);
        if (balance_factor(current) == 2) {
            if (balance_factor(tree[current]->right) < 0) {
                tree[current]->right = rotate_right(tree[current]->right);
            }
            return rotate_left(current);
        }
        if (balance_factor(current) == -2) {
            if (balance_factor(tree[current]->left) > 0) {
                tree[current]->left = rotate_left(tree[current]->left);
            }
            return rotate_right(current);
        }
        return current;
    }

    int insert(int x, int current) {
        if (current == -1) {
            tree.push_back(new Node(x, -1, -1, 1));
            return tree.size() - 1;
        }
        else {
            if (x < tree[current]->value) {
                tree[current]->left = insert(x, tree[current]->left);
            }
            else {
                tree[current]->right = insert(x, tree[current]->right);
            }
            return balance(current);
        }
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

    int X;
    std::cin >> X;

    if (N == 0) {
        std::cout << 1 << '\n';
        std::cout << X << ' ' << 0 << ' ' << 0;
        return 0;
    }

    tree.calculate_height(0, 0);

    tree.head = tree.balance(0);

    tree.head = tree.insert(X, tree.head);

    tree.Smth(tree.head);

    std::cout << tree.tree.size() << '\n';

    tree.pre_order_bypass(tree.head);

    return 0;
}
