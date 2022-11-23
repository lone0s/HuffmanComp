#include <iostream>
#include "PriorityQueue/PriorityQueue.h"
#include "Tree/FTree.h"
#include "Huffman/HData.h"
#include "Huffman/HCompressor.h"
#include "Utils/Utils.h"
#include <sstream>

using namespace Huffman;
using namespace FrequencyTree;
using namespace PQueue;
using namespace std;


int test() {
    Node* testCompare = new Node('a',5);
    FTree a (testCompare);
    FTree b(testCompare);
    FTree* x = new FTree(a);
    FTree* y = new FTree(b);
    cout << "TEST COMPARAISON\n";
    cout << ((a == b) ? "A = B" : "A != B") << endl;
    cout << ((a == *x) ? "A = X" : "A != X") << endl;
    cout << ((b == *y) ? "B = Y" : "B != Y") << endl;
    cout << ((*x == *y) ? "X = Y" : "X != Y") << endl;
    cout << ((x == y) ? "&X = &Y" : "&X != &Y") << endl;
    return 0;
}

int main() {
    FTree a('a',5);
    FTree b('b', 10);
    FTree c('c', 5);
/*    FTree d('d', 20);*/
    int freq[26] {0};
    freq[0] = 5;
    freq[1] = 10;
    freq[2] = 5;
    vector<FTree*> testVec {&a,&b,&c/*,&d*/};
    string buf ;


    HData test;
    test.setLetterFrequ(freq);
    test.setFileHasBeenRead(true);
    test.init();

    cout << test.tree << endl;
//    cout << *res;
    HCompressor testC(test);
    testC.initPatterns(test.tree, buf, ' ');
    for (auto& elem : testC.encodedPatterns) {
        cout << elem.second << endl;
    };
    testC.encodedPatterns.find('b');
return 0;
}

int mainMain() {
    HData test;
    int array[26];
    fillArrayWithRandValues(array);

    test.setLetterFrequ(array);
    int tot = total(array);
    float freqA = fFrequency(array[0],tot);
    test.setFileHasBeenRead(true);
    cout << tot << endl;
    cout << freqA << endl;
    test.init();
    cout << test . tree << endl;

    vector<char> treeChars;
    charsInTree(test.tree,treeChars);

    for(auto c : treeChars) {
        cout << c << " | ";
    }
    cout << endl;

    cout << "Size test : \n" <<
    ((treeChars.size() == nbLeafs(test.tree))? "Same size\n" : "Not the same size\n") <<
    nbLeafs(test.tree) << endl << treeChars.size() << endl;
}

