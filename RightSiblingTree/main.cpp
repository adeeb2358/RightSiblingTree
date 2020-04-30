//
//  main.cpp
//  RightSiblingTree
//
//  Created by adeeb mohammed on 27/04/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
// time complexity is o(n) space complexity is  o(d) o(log(n)) for perfectly balanced tree

#include <iostream>

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left = NULL;
  BinaryTree *right = NULL;

BinaryTree(int value);
};

void mutateTree(BinaryTree *tree,
                BinaryTree *parent,
                bool isLeftChild){
    if(tree == nullptr){
        return;
    }
    
    auto left  = tree->left;
    auto right = tree->right;
    
    mutateTree(left, tree, true);
    if (parent == nullptr) {
        tree->right = nullptr;
    }else if(isLeftChild){
        tree->right = parent->right;
    }else {
        if (parent->right  == nullptr) {
            tree->right = nullptr;
        }else{
            tree->right = parent->right->left;
        }
    }
    mutateTree(right, tree, false);
}

BinaryTree *rightSiblingTree(BinaryTree *root) {
    mutateTree(root, nullptr, false);
    return root;
}

int main(int argc, const char * argv[]) {
    std::cout << "Making the Binary Tree a Right Sibling Tree" << std::endl;
    return 0;
}
