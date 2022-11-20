//
// Created by jeune on 17/11/2022.
//

#pragma once

#include "Cell.h"

namespace PQueue {
    class PriorityQueue {
        PCell* top;

    public:
        PriorityQueue() : top(nullptr) {};
        explicit PriorityQueue(PCell* cell) : top(cell) {};

        inline int headVal() const {
            return this -> top -> headV();
        };

        inline int headPrio() const {
            return this -> top -> headP();
        };

        inline PriorityQueue tail() const {
            return *new PriorityQueue(top -> tail());
        }

        friend int size(PriorityQueue queue){
            return cSize(queue.top);
        }

        friend PriorityQueue addElement(int val, int prio, PriorityQueue queue) {
            return *new PriorityQueue(add(val,prio,queue.top));
        };

        friend std::ostream& operator << (std::ostream& ostream, PriorityQueue queue) {
            ostream << "[";
            ostream << queue.top;
            ostream << "]\n";
            return ostream;
        }
    };
}

