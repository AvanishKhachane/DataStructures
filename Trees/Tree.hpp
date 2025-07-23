#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include <vector>
#include <functional>

template <typename T>
class TreeNode {
public:
    T data;
    std::vector<std::unique_ptr<TreeNode<T>>> children;

    explicit TreeNode(const T& value);
    void addChild(std::unique_ptr<TreeNode<T>> child);
};

template <typename T>
class Tree {
public:
    std::unique_ptr<TreeNode<T>> root;

    Tree() = default;
    explicit Tree(const T& rootData);

    TreeNode<T>* insert(TreeNode<T>* parent, const T& value);

    void traversePreOrder(const std::function<void(const T&)>& visit) const;

private:
    void traversePreOrderHelper(const TreeNode<T>* node, const std::function<void(const T&)>& visit) const;
};

#include "Tree.cpp"  // Templated implementation

#endif  // TREE_HPP
