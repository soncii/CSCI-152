#include "set.h"
#include <iostream>

treenode *copynodes(treenode *original)
{
    if (original == nullptr)
        return nullptr;
    treenode *root = new treenode(original->value);
    root->left = original->left;
    root->right = original->right;
    if (original->left != nullptr)
    {
        root->left = copynodes(original->left);
    }
    if (original->right != nullptr)
    {
        root->right = copynodes(original->right);
    }
    return root;
}
void deallocatenodes(treenode *node)
{
    if (node == nullptr)
        return;
    treenode *L = node->left;
    treenode *R = node->right;
    delete node;
    deallocatenodes(L);
    deallocatenodes(R);
}

bool set::contains(int i) const
{
    treenode *traverse = root;
    while (traverse != nullptr)
    {
        if (traverse->value == i)
            return true;
        if (traverse->value > i)
            traverse = traverse->left;
        else
            traverse = traverse->right;
    }
    return false;
}

bool set::insert(int i)
{
    if (root == nullptr)
    {
        root = new treenode(i);
        set_size++;
        return true;
    }
    if (contains(i))
        return false;
    treenode *traverse = root;
    treenode *prev;
    while (traverse != nullptr)
    {
        prev = traverse;
        if (traverse->value > i)
            traverse = traverse->left;
        else
            traverse = traverse->right;
    }
    traverse = new treenode(i);
    if (prev->value > traverse->value)
        prev->left = traverse;
    else
        prev->right = traverse;
    set_size++;
    return true;
}

void set::clear()
{
    deallocatenodes(root);
    root = nullptr;
    set_size = 0;
}

size_t set::size() const
{
    return set_size;
}

bool set::empty() const
{
    return size() == 0;
}
