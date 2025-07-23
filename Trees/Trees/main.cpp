#include <iostream>
#include "Tree.hpp"

int main() {
    Tree<std::string> tree("Root");

    TreeNode<std::string>* child1 = tree.insert(tree.root.get(), "Child 1");
    TreeNode<std::string>* child2 = tree.insert(tree.root.get(), "Child 2");
    TreeNode<std::string>* child3 = tree.insert(tree.root.get(), "Child 3");

    tree.insert(child1, "Grandchild 1.1");
    tree.insert(child1, "Grandchild 1.2");
    tree.insert(child2, "Grandchild 2.1");

    tree.traversePreOrder([](const std::string& val) 
        {
            std::cout << val << '\n';
        });

    {

        std::cin.read(nullptr, 0); // Wait for user input before exiting
        return 0;
	}
}
