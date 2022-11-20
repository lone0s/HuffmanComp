//
// Created by jeune on 17/11/2022.
//

#pragma once
#include "../Tree/Node.h"
#include "../PriorityQueue/PriorityQueue.h"
#include "../Tree/FTree.h"

using namespace FrequencyTree;
using namespace PQueue;
namespace Huffman {
    class HData {
        int letterFreq[26] = {0};
        bool fileHasBeenRead = false;

        PriorityQueue queue;

        //Fonctions
        /*
         * Initialise arbre de fréquence
         */
        void initFrequencyTree();

    public:
        FTree tree;
        HData() : tree(nullptr), queue(nullptr){};

        //Devrait eventuellement inclure la lecture du fichier
        inline void init() {initFrequencyTree();};

        const int *getLetterFreq() const;
        inline void setLetterFrequ(int test[26]) {
            for(size_t i = 0 ; i < 26 ; ++i) {
                letterFreq[i] = test[i];
            }
        };

        bool isFileHasBeenRead() const;

        void setFileHasBeenRead(bool fileHasBeenRead);
    };
}
