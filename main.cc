#include <iostream>

#include "algo.h"

namespace BSTTraversal
{
struct Node
{
    explicit Node(const std::string& name) : name(name) {}

    Node* left = nullptr;
    Node* right = nullptr;

    std::string name;
};

static void f(Node* n)
{
    if (!n)
        return;

    std::cout << n->name << " ";
}

static void dump_tree()
{
    std::cout << "Input Tree:\n";
    std::cout << "    1\n";
    std::cout << "   /\n";
    std::cout << "  2\n";
    std::cout << " / \\\n";
    std::cout << "3   4" << std::endl;
}

static Node* build_tree()
{
    Node* root = new Node("1");
    root->left = new Node("2");
    root->left->left = new Node("3");
    root->left->right = new Node("4");

    return root;
}

static void traverse_tree(Node* root)
{
    std::cout << "Traverse: ";
    AlgoCpp::BSTTraversal<Node>(root, std::function<void(Node*)>(f));
    std::cout << std::endl;
}

static void destroy_tree(Node* root)
{
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;
}

void Run_BSTTraversal()
{
    std::cout << "==== BST Traversal\n";

    dump_tree();
    Node* root = build_tree();
    traverse_tree(root);
    destroy_tree(root);

    std::cout << "====" << std::endl;
}
} // BSTTraversal

int main(int argc, char** argv)
{
    BSTTraversal::Run_BSTTraversal();

    return 0;
}

