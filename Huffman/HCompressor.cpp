//
// Created by jeune on 17/11/2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "HCompressor.h"
using namespace Huffman;
void Huffman::HCompressor::generateEncoding() {
    FTree tree = this -> data.tree;
    int* chars = this -> data . getArrayFqcy();
    std::stringstream stringBuilder;
    stringBuilder << "0";
}

void Huffman::HCompressor::init(const std::string&inputFile) {
    std::ifstream inputStream(inputFile);
    if (inputStream.is_open()) {
        char outputC;
        std::string buffer;
        FTree tree = this -> data.tree;
        while (!inputStream.eof()) {
            outputC = inputStream.get();
            buffer = "";
            initPatterns(tree,buffer,outputC);
        }
    }
    inputStream.close();
}

void Huffman::HCompressor::initPatterns(FTree tree, std::string buffer, char toPush) {
    if (!empty(tree)) {
        if (isLeaf(tree)) {
            buffer.append(sizeof (char),toPush);
            encodedPatterns.emplace(tree.rLetter(),buffer);
        } else {
            if(toPush != ' ')
                buffer.append(sizeof (char),toPush);
            initPatterns(tree.lson(), buffer, '0');
            initPatterns(tree.rson(), buffer, '1');
        }
    }
}

void HCompressor::encode(const std::string& inputFile, const std::string& outputFile) const {
    std::ifstream inputStream(inputFile);
    std::ofstream outputStream(outputFile);
    if (inputStream.is_open() && outputStream.is_open()) {
        char inputC;
        std::string temp;
//        std::string outputPattern; USELESS
        while (!inputStream.eof()) {
            inputC = inputStream.get();
            temp = encodedPatterns.find(inputC)-> second.c_str();
            outputStream.write(temp.c_str(), temp.size());
        }
        inputStream.close();
        outputStream.close();
    }
}

void HCompressor::decode(const std::string& inputFile, const std::string& outputFile) const {
    std::ifstream inputStream(inputFile);
    std::ofstream outputStream(outputFile);
    if (inputStream.is_open() && outputStream.is_open()){
        char inputC,outputC;
        while (!inputStream.eof()) {
            FTree tree = this->data.tree;
            inputC = '\0';
            outputC = '\0';
            while (true) {
                inputC = inputStream.get();
                if (isLeaf(tree)) {
                    outputC = tree.rLetter();
                    outputStream.put(outputC);
                    outputC = '\0';
                    break;
                }
                else {
                    switch (inputC) {
                        case 0 :
                            tree = tree.rson();
                        case 1 :
                            tree = tree.lson();
                    }
                }
            }
        }
        inputStream.close();
        outputStream.close();
    }
}