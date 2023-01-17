//
// Created by LociStar on 13.01.2023.
//

#ifndef CHESSENGINE_TRANSPOSITIONTABLE_H
#define CHESSENGINE_TRANSPOSITIONTABLE_H

#include <unordered_map>
#include <cstdint>
#include <climits>

const int TABLE_SIZE = 500000;

class TranspositionTable {
public:
    struct Entry {
        // Zobrist key
        uint64_t key{};
        // Type of entry: exact value 0, lower bound 1, upper bound 2
        int type{};
        // Depth of the search
        int depth{};
        // Score/Evaluation of the position
        int score{};
        // Age of the entry
        int age{};
        // Node type: PV, Cut or All
        int nodeType{};
        // Alpha and Beta values
        int alpha{};
        int beta{};
    };

    TranspositionTable() {
        age = 0;
    }

    // Lookup an entry in the table
    Entry* lookup(uint64_t key) {
        auto it = table.find(key);
        if (it == table.end()) {
            // Entry not found
            return nullptr;
        }
        return &it->second;
    }

    // Store an entry in the table
    void store(uint64_t key, Entry entry) {
        age++;
        entry.age = age;
        if (table.size() >= TABLE_SIZE) {
            // Find the least recently used entry
            uint64_t lruKey = -1;
            int minAge = INT_MAX;
            for (auto& [k, v] : table) {
                if (v.age < minAge) {
                    minAge = v.age;
                    lruKey = k;
                }
            }
            // Remove the least recently used entry
            table.erase(lruKey);
        }
        table[key] = entry;
    }

    unsigned long long size() {
        return table.size();
    }

private:
    std::unordered_map<uint64_t, Entry> table;
    int age;
};

#endif //CHESSENGINE_TRANSPOSITIONTABLE_H
