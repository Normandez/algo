#include <iostream>

#include "algo.h"

struct Node
{
    explicit Node(const std::string& name) : name(name) {}

    Node* left = nullptr;
    Node* right = nullptr;

    std::string name;
};

void f(Node* n)
{
    if (!n)
        return;

    std::cout << n->name << std::endl;
}

int main(int argc, char** argv)
{
    // root
    Node* root = new Node("root");

    // root->left
    root->left = new Node("root->left");

    // root->left->left
    root->left->left = new Node("root->left->left");

    // root->left->right
    root->left->right = new Node("root->left->right");

    AlgoCpp::bst_traversal<Node>(root, std::function<void(Node*)>(f));

    return 0;
}

