//
// Created by LociStar on 16.01.2023.
//

#ifndef CHESSENGINE_PVTABLE_H
#define CHESSENGINE_PVTABLE_H

#include <unordered_map>
#include <cstdint>
#include <climits>
#include "position.h"

class PVTable {
public:
    std::unordered_map<uint64_t, Move> table;

    void store(uint64_t key, Move move) {
        table[key] = move;
    }

    Move lookup(uint64_t key) {
        if (table.count(key) > 0) {
            return table[key];
        }
        return Move();
    }
};

#endif //CHESSENGINE_PVTABLE_H
