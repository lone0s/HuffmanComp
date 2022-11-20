//
// Created by jeune on 17/11/2022.
//
#include <iostream>

#pragma once
namespace FrequencyTree {
    class Node {
        char letter;
        int frequency;
        Node* left;
        Node* right;

    public:
        Node(char root, int f) : letter(root), frequency(f), left(nullptr), right(nullptr) {};
        Node(char root, int f, Node* lson, Node* rson) : letter(root), frequency(f), left(lson),right(rson) {};
        inline Node* lson()
        {
            if (left)
                return left;
        };

        inline Node* rson()
        {
                if (right)
            return right;
        };

        inline int rootLetter() const {return letter;};
        inline int rootFrequency() const {return frequency;};

        friend std::ostream& operator << (std::ostream& os, const Node* tree) {
            os << "[";
            if (tree != nullptr) {
                os << "[" << tree->letter <<"=";
                os << tree -> frequency << "]";
                os << (tree->left);
                os << (tree->right);
            }
            os << "]";
            return os;
        }

        friend bool nodeLeaf(Node* node) {
            return (!(node -> left) && !(node -> right));
        }
//        friend void addLetterWithFreq(char l, int f, Node* tree) {
//            if (tree) {
//                if (!(tree -> left && !(tree -> right))) {
//                    tree->letter = l;
//                    tree -> frequency = f;
//                }
//                else {
//                    addLetterWithFreq(l,f,)
//                }
//            }
//        }
    };
}