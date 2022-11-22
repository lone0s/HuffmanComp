//
// Created by jeune on 17/11/2022.
//
#include <vector>
#include <algorithm>
#include "../Tree/FTree.h"
#pragma once

using namespace FrequencyTree;
inline FTree* getMinOfFtrees(std::vector<FTree*>& trees) {
    int fMin = trees.front() -> rFreq();
    int cpt = 0;
    int index = 0;
    for (auto& t : trees) {
        if (fMin > (t -> rFreq())) {
            fMin = t -> rFreq();
            index = cpt;
        }
        cpt++;
    }
    auto res = new FTree(*trees.at(index));
    trees.erase(trees.begin() + index);
    return res;
}

inline FTree* min(FTree* t1, FTree* t2) {
    return (t1 -> rFreq() < t2 -> rFreq() ? t1 : t2);
}


inline FTree* max(FTree* t1, FTree* t2) {
    return (t1 -> rFreq() >= t2 -> rFreq() ? t1 : t2);
}

inline char getLetterOfIndex(int l) {
    return char('a' + l);
}

inline int total(const int array[26]) {
    int sum = 0;
    for(size_t i = 0 ; i < 26 ; ++i) {
        sum += array[i];
    }
    return sum;
}


inline int getBase(int total) {
    int base = 10;
    while(total > 1) {
        total /= 10;
        base *= 10;
    }
    return base;
}
inline int iFrequency(int value, int total) {
    return (value * getBase(total) / total);
}

inline float fFrequency(int value, int total) {
    return ((float)value *(float) getBase(total) /(float) total);
}

inline void fillArrayWithRandValues(int array[26]) {
    for(size_t i = 0 ; i < 26 ; ++i ) {
        array[i] = rand() % 10;
    }
}

inline void charsInTree(FTree tree, std::vector<char>& res) {
    if (!empty(tree)) {
        if(isLeaf(tree) && (tree . rLetter() != '.') )
            res.push_back(tree . rLetter());
        else {
            charsInTree(tree .lson(),res);
            charsInTree(tree.rson(), res);
        }
    }
}

inline std::vector<char> charsInArray(const int array[]) {
    std::vector<char> res;
    for(int i = 0 ; i < 26 ; ++i) {
        if (array[i] != 0) {
            res.push_back(getLetterOfIndex(i));
        }
    }
    return res;
}

inline bool hasDuplicates(std::vector<char>& vec) {
//    auto it = std::unique(vec.front(),vec.end());
}

inline int nbLeafs(FTree tree) {
    if (empty(tree)) {
        return 0;
    }
    else if (isLeaf(tree)) {
        return 1;
    }
    else {
        return nbLeafs(tree . lson()) + nbLeafs(tree.rson());
    }
}

inline int treeDepth(FTree tree) {
    if (empty(tree)) {
        return 0;
    }
    else {
        int left = 1 + treeDepth(tree . lson());
        int right = 1 + treeDepth(tree.rson());
        return (left >= right) ? left : right;
    }
}