cmake_minimum_required(VERSION 3.23)
project(huffhuffPass)

set(CMAKE_CXX_STANDARD 14)

add_executable(huffhuffPass main.cpp Huffman/HCompressor.cpp Huffman/HCompressor.h Huffman/HData.cpp Huffman/HData.h Tree/Node.h Tree/FTree.h PriorityQueue/Cell.h PriorityQueue/PriorityQueue.h Tree/FTree.cpp Utils/Utils.h)
