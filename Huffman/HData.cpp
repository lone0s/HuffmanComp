//
// Created by jeune on 17/11/2022.
//

#include <vector>
#include "HData.h"
#include "../Utils/Utils.h"

using namespace Huffman;
void HData::initFrequencyTree() {
    if (fileHasBeenRead){
        std::vector<FTree *> trees;
        int cpt = 0;

        //Init all letters and their frequencies
        for (int freq: letterFreq) {
            if (freq > 0) {
                trees.push_back(new FTree(getLetterOfIndex(cpt), freq));
            }
            cpt++;
        }

        // Need construire des arbres a partir des minimums
        FTree *min1;
        FTree *min2;
        while (true) {
            if (trees.size() == 1)
                break;
            min1 = getMinOfFtrees(trees);
            min2 = getMinOfFtrees(trees);
            trees.push_back(new FTree('.',
                                      min1->rFreq() + min2->rFreq(),
                                      max(min1,min2),
                                      min(min1, min2)
            ));
        }
        //On a maintenant arbre composé de fréquences cummulées;
        this->tree = *trees.front();
    }
}

const int *HData::getLetterFreq() const {
    return letterFreq;
}

bool HData::isFileHasBeenRead() const {
    return fileHasBeenRead;
}

void HData::setFileHasBeenRead(bool fileHasBeenRead) {
    HData::fileHasBeenRead = fileHasBeenRead;
}
