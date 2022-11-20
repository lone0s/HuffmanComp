//
// Created by jeune on 17/11/2022.
//

#pragma once

#include "Node.h"

namespace FrequencyTree {
    class FTree {
        Node* root;
    public:
        FTree() : root(nullptr) {};
        explicit FTree(Node* node) : root(node) {};
        FTree(char letter, int freq) : root(new Node(letter,freq)) {};
        bool operator==(const FTree& tree) {
            return this -> root == tree . root;
        }
        FTree(char letter, int freq, FTree* l, FTree* r) {
            this -> root = new Node(letter,freq,l ->root, r -> root);
        };

        inline int rLetter() const {
            if (this -> root)
                return root->rootLetter();
            else
                throw std::invalid_argument("Empty tree\n");
        };

        inline int rFreq() const {
            return root -> rootFrequency();
        }

        inline FTree lson() const {
            return *new FTree (this->root ->lson());
        }

        inline FTree rson() const {
            return *new FTree (this -> root -> rson());
        }

        friend std::ostream& operator << (std::ostream& os, const FTree& tree) {
            os << tree.root;
            return os;
        };

        friend bool empty(FTree tree) {
            return (!tree.root);
        }

        friend bool isLeaf(FTree tree) {
            return(nodeLeaf(tree . root));
        }
    };
}