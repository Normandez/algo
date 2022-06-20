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

static void Run_BSTTraversal()
{
    std::cout << "==== BST Traversal\n";

    dump_tree();
    Node* root = build_tree();
    traverse_tree(root);
    destroy_tree(root);

    std::cout << "====" << std::endl;
}
} // BSTTraversal

namespace LookAndSaySequence
{
using Sequence = std::vector<std::string>;

static void print(const std::string& title, const Sequence& seq)
{
    std::cout << title << ": ";
    for (const auto& member : seq)
        std::cout << member << " ";

    std::cout << std::endl;
}

static void Run_LookAndSaySequence()
{
    std::cout << "==== Look-and-say sequence\n";

    print("zero gen", AlgoCpp::LookAndSaySequence("1", 0));
    print("empty seed", AlgoCpp::LookAndSaySequence(""));
    print("empty both", AlgoCpp::LookAndSaySequence("", 0));
    print("not digit", AlgoCpp::LookAndSaySequence("1a2"));

    print("default", AlgoCpp::LookAndSaySequence());
    print("degenerate", AlgoCpp::LookAndSaySequence("22"));

    print("one gen", AlgoCpp::LookAndSaySequence("1", 1));
    print("two gen", AlgoCpp::LookAndSaySequence("1", 2));
    print("three gen", AlgoCpp::LookAndSaySequence("1", 3));
    print("ten gen", AlgoCpp::LookAndSaySequence("1", 10));

    print("seed 2", AlgoCpp::LookAndSaySequence("2"));
    print("seed 3", AlgoCpp::LookAndSaySequence("3"));

    print("seed 111", AlgoCpp::LookAndSaySequence("111"));
    print("seed 222", AlgoCpp::LookAndSaySequence("222"));
    print("seed 33", AlgoCpp::LookAndSaySequence("33"));

    print("seed 1234", AlgoCpp::LookAndSaySequence("1234"));

    std::cout << "====" << std::endl;
}
} // LookAndSaySequence

int main(int argc, char** argv)
{
    BSTTraversal::Run_BSTTraversal();
    LookAndSaySequence::Run_LookAndSaySequence();

    return 0;
}

