//
// Created by jeune on 17/11/2022.
//
#include <iostream>

#pragma once

namespace PQueue {
    class PCell {
        int value;
        int priority;
        PCell *next;

    public:
        PCell(int val, int prio) : value(val), priority(prio), next{nullptr} {};

        explicit PCell(const PCell *cell) : value(cell->value), priority(cell->priority), next(cell->next) {};

        PCell(int val, int prio, PCell *cell) : value(val), priority(prio), next(cell) {};

        inline int headV() const {
            return this->value;
        }

        inline int headP() const {
            return this->priority;
        }

        inline PCell *tail() const {
            return this->next;
        }

        friend PCell *add(int val, int prio, PCell *pQueue) {
            if (!pQueue) {
                return new PCell(val, prio);
            } else if (prio > pQueue->priority) {
                return new PCell(val, prio, pQueue);
            } else {
                return new PCell(pQueue->value, pQueue->priority, add(val, prio, pQueue->next));
            }
        }

        friend int cSize(PCell* pQueue) {
            if (!pQueue) {
                return 0;
            }
            else {
                return 1 + cSize(pQueue->next);
            }
        }

        friend std::ostream &operator<<(std::ostream &ostream, const PCell *pCell) {
//            ostream << "[V;P]\n";
//            ostream << "[";
//            auto* current = new PCell(pCell);
//            while(current) {
//                ostream << "[" << current->value << ";" << current ->priority << "]";
//                if (current -> next)
//                    ostream << " | ";
//                current = current -> next;
//            }
//            ostream << "]\n";
            if (!pCell) {
                return ostream;
            } else {
                ostream << "[" << pCell->value << ";" << pCell->priority << "]";
                if (pCell->next)
                    ostream << " | ";
                ostream << pCell->next;
            }
            return ostream;
        };
    };
}