//
// Created by jeune on 17/11/2022.
//

#pragma once

#include <string>
#include <unordered_map>
#include "HData.h"

namespace Huffman {
    class HCompressor {
        HData data;

        void generateEncoding();

    public:
        std::unordered_map<char,std::string/*Lettre,Encodage binaire*/> encodedPatterns;
        void encodeSearch(FTree tree,std::string buffer,char toPush);
        HCompressor(const HData& h){this -> data = h;};
    };
}


