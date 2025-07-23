#ifndef TREE_TPP
#define TREE_TPP

#include "Tree.hpp"

template <typename T>
TreeNode<T>::TreeNode(const T& value) : data(value) {}

template <typename T>
void TreeNode<T>::addChild(std::unique_ptr<TreeNode<T>> child) {
    children.push_back(std::move(child));
}

template <typename T>
Tree<T>::Tree(const T& rootData) {
    root = std::make_unique<TreeNode<T>>(rootData);
}

template <typename T>
TreeNode<T>* Tree<T>::insert(TreeNode<T>* parent, const T& value) {
    if (!parent) return nullptr;
    auto newNode = std::make_unique<TreeNode<T>>(value);
    TreeNode<T>* rawPtr = newNode.get();
    parent->addChild(std::move(newNode));
    return rawPtr;
}

template <typename T>
void Tree<T>::traversePreOrder(const std::function<void(const T&)>& visit) const {
    traversePreOrderHelper(root.get(), visit);
}

template <typename T>
void Tree<T>::traversePreOrderHelper(const TreeNode<T>* node, const std::function<void(const T&)>& visit) const {
    if (!node) return;
    visit(node->data);
    for (const auto& child : node->children) {
        traversePreOrderHelper(child.get(), visit);
    }
}

#endif  // TREE_TPP
