//
// Created by jeune on 17/11/2022.
//

#include <iostream>
#include <sstream>
#include "HCompressor.h"

void Huffman::HCompressor::generateEncoding() {
    FTree tree = this -> data.tree;
    int* chars = this -> data . getArrayFqcy();
    std::stringstream stringBuilder;
    stringBuilder << "0";
}

//std::stringstream add(std::stringstream& buffer, int x) {
//    switch (x) {
//        case 0 :
//            return (buffer << 0);
//    }
//}

void Huffman::HCompressor::encodeSearch(FTree tree,std::string buffer,char toPush) {
    if (!empty(tree)) {
        if (isLeaf(tree)) {
            buffer.append(sizeof (char),toPush);
            encodedPatterns.emplace(tree.rLetter(),buffer);
        } else {
            if(toPush != ' ')
                buffer.append(sizeof (char),toPush);
            encodeSearch(tree.lson(),buffer,'0');
            encodeSearch(tree.rson(),buffer, '1');
        }
    }
}
