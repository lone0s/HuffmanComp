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
        std::unordered_map<char,std::string/*Lettre, Pattern*/> encodedPatterns;
        void initPatterns(FTree tree, std::string buffer, char toPush);
        void init(const std::string& inputFile);
        explicit HCompressor(const HData& h){this -> data = h;};
        void decode(const std::string& inputFile, const std::string& outputFile) const;
        void encode(const std::string& inputFile, const std::string& outputFile) const;
    };
}


