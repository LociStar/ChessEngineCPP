//
// Created by LociStar on 28.09.2020.
//

#include "engine.h"
#include <bitset>
#include <chrono>
#include "positionTables.h"

template<Color Us>
int Engine::negamax(Position *pos, int depth, int alpha, int beta, bool first) {

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // Check if the time taken has exceeded the time control
    if (elapsed.count() > timeControl) {
        return quiescenceSearch<Us>(pos, alpha, beta, 17);
    }

    int alphaOrig = alpha;
    //tableNode tableNode = transposition.get(key);
    counter++;

    //TT lookup
    auto entry = tt.lookup(pos->get_hash());
    if (entry != nullptr && entry->depth >= depth) {
        switch (entry->type) {
            case 0: //exact
                return entry->score;
            case 1: //lower bound
                alpha = std::max(alpha, entry->score);
                break;
            case 2: //upper bound
                beta = std::min(beta, entry->score);
                break;
        }
        if (alpha >= beta) {
            return entry->score;
        }
    }
    Move bestLocalMove;
    Move pv = pvTable.lookup(pos->get_hash());
    if (pv != Move()) {
        bestLocalMove = pv;
        //bestLocalMove = pv;
    }

    int move_score = 0;
    if (depth <= 0) {
        move_score = quiescenceSearch<Us>(pos, alpha, beta, 50);
        return move_score;
    }

    if (isDraw()) {
        return 0;
    }
    if (isCheckMate()) {
        return -9000 * depth;
    }

    int best_score = -999999999; // Negative-Infinity
    MoveList<Us> moveList(*pos);
    moveList.sort(&position, &pvTable);

    for (Move move: moveList) {
        pos->play<Us>(move);
        move_score = -negamax<~Us>(pos, depth - 1, -beta, -alpha, false);
        pos->undo<Us>(move);

        if (move_score > best_score) {
            best_score = move_score;
            bestLocalMove = move;
            pvTable.store(pos->get_hash(), bestLocalMove);
        }
        alpha = std::max(alpha, best_score);
        if (alpha >= beta) {
            break;
        }
    }
    //store in TT
    entry = new TranspositionTable::Entry();
    entry->score = best_score;
//    entry->pvMove = bestMove;
    if (entry->score <= alphaOrig) {
        entry->type = 2;
    } else if (entry->score >= beta) {
        entry->type = 1;
    } else {
        entry->type = 0;
    }
    entry->depth = depth;
    tt.store(pos->get_hash(), *entry);

    return best_score;
}

template<Color Us>
int Engine::quiescenceSearch(Position *pos, int alpha, int beta, int depth) {
    counter++;
    int standpat = evaluation();
    if (standpat >= beta) {
        return beta;
    } else if (alpha < standpat) {
        alpha = standpat;
    }

    if (depth == 0) {
        return alpha;
    }

    //do the move generation for captures and checks
    CaptureList<Us> captureList(position);

    if (captureList.size() == 0) {
        if (isCheckMate()) {
            return -9000 * depth;
        }
        if (isDraw()) {
            return 0;
        }
    }
    // sort capture list
    // captureList.sort(&position, &pvTable);

    for (Move move: captureList) {
        //if (move.is_capture()) {
            pos->play<Us>(move);
            int score = -quiescenceSearch<~Us>(pos, -beta, -alpha, depth - 1);
            pos->undo<Us>(move);
            if (score >= beta) {
                return beta;
            } else if (score > alpha) {
                alpha = score;
            }
//            alpha = std::max(alpha, score);
//            if (alpha >= beta) {
//                break;
//            }
        //}
    }

    return alpha;
}

void evalPawn(Position *position, int *value) {
    auto x = static_cast<unsigned long long>(position->bitboard_of(WHITE_PAWN));
    //unsigned long long fix for issue pointed out by @Zac Howland in comments
    unsigned int count = 0;//number bits
    while (x != 0) {
        unsigned long long bit = x & 1;
        if (bit == 1) {
            *value += pawn[63 - count] + 100;
        }
        x >>= 1;
        count++;
    }
    x = static_cast<unsigned long long>(position->bitboard_of(BLACK_PAWN));
    //unsigned long long fix for issue pointed out by @Zac Howland in comments
    count = 0;//number of 1 bits
    while (x != 0) {
        unsigned long long bit = x & 1;
        if (bit == 1) {
            *value -= pawn[count] + 100;
        }
        x >>= 1;
        count++;
    }
}

void evalKnight(Position *position, int *value) {
    auto x = static_cast<unsigned long long>(position->bitboard_of(WHITE_KNIGHT));
    //unsigned long long fix for issue pointed out by @Zac Howland in comments
    unsigned int count = 0;//number of 1 bits
    while (x != 0) {
        unsigned long long bit = x & 1;
        if (bit == 1) {
            *value += knight[63 - count] + 300;
        }
        x >>= 1;
        count++;
    }
    x = static_cast<unsigned long long>(position->bitboard_of(BLACK_KNIGHT));
    //unsigned long long fix for issue pointed out by @Zac Howland in comments
    count = 0;//number of 1 bits
    while (x != 0) {
        unsigned long long bit = x & 1;
        if (bit == 1) {
            *value -= knight[count] + 300;
        }
        x >>= 1;
        count++;
    }
}

void evalBishop(Position *position, int *value) {
    auto x = static_cast<unsigned long long>(position->bitboard_of(WHITE_BISHOP));
    //unsigned long long fix for issue pointed out by @Zac Howland in comments
    unsigned int count = 0;//number of 1 bits
    while (x != 0) {
        unsigned long long bit = x & 1;
        if (bit == 1) {
            *value += bishop[63 - count] + 300;
        }
        x >>= 1;
        count++;
    }
    x = static_cast<unsigned long long>(position->bitboard_of(BLACK_BISHOP));
    //unsigned long long fix for issue pointed out by @Zac Howland in comments
    count = 0;//number of 1 bits
    while (x != 0) {
        unsigned long long bit = x & 1;
        if (bit == 1) {
            *value -= bishop[count] + 300;
        }
        x >>= 1;
        count++;
    }
}

void evalKing(Position *position, int *value) {
    auto x = static_cast<unsigned long long>(position->bitboard_of(WHITE_KING));
    //unsigned long long fix for issue pointed out by @Zac Howland in comments
    unsigned int count = 0;//number of 1 bits
    while (x != 0) {
        unsigned long long bit = x & 1;
        if (bit == 1) {
            *value += king[63 - count];
        }
        x >>= 1;
        count++;
    }
    x = static_cast<unsigned long long>(position->bitboard_of(BLACK_KING));
    //unsigned long long fix for issue pointed out by @Zac Howland in comments
    count = 0;//number of 1 bits
    while (x != 0) {
        unsigned long long bit = x & 1;
        if (bit == 1) {
            *value -= king[count];
        }
        x >>= 1;
        count++;
    }
}

int Engine::evaluation() {
    int materialScore = 900 * (std::bitset<64>(position.bitboard_of(WHITE_QUEEN)).count() -
                               std::bitset<64>(position.bitboard_of(BLACK_QUEEN)).count())
                        + 500 * (std::bitset<64>(position.bitboard_of(WHITE_ROOK)).count() -
                                 std::bitset<64>(position.bitboard_of(BLACK_ROOK)).count());

    //value from positioning
    int value = 0;
    evalPawn(&position, &value);
    evalBishop(&position, &value);
    evalKnight(&position, &value);
    evalKing(&position, &value);


    if (position.turn() == 0) return materialScore + value;
    else return (materialScore + value) * (-1);

}

/*template<Color Us>
int Engine::evaluation_2() {
    int materialScore = 900 * (std::bitset<64>(position.bitboard_of(WHITE_QUEEN)).count() -
                               std::bitset<64>(position.bitboard_of(BLACK_QUEEN)).count())
                        + 500 * (std::bitset<64>(position.bitboard_of(WHITE_ROOK)).count() -
                                 std::bitset<64>(position.bitboard_of(BLACK_ROOK)).count())
                        + 300 * (std::bitset<64>(position.bitboard_of(WHITE_KNIGHT)).count() -
                                 std::bitset<64>(position.bitboard_of(BLACK_KNIGHT)).count())
                        + 300 * (std::bitset<64>(position.bitboard_of(WHITE_BISHOP)).count() -
                                 std::bitset<64>(position.bitboard_of(BLACK_BISHOP)).count())
                        + 100 * (std::bitset<64>(position.bitboard_of(WHITE_PAWN)).count() -
                                 std::bitset<64>(position.bitboard_of(BLACK_PAWN)).count());

    if (Us == WHITE) return materialScore;
    else return materialScore * (-1);

}*/

bool Engine::isDraw() {
    if (isRepetition()) {
        //    std::cout << "rep" << std::endl;
        return true;
    }
    //std::cout << "InM" << std::endl;
    if (isInsufficientMaterial()) return true;
    //std::cout << "halfMove" << std::endl;
    if (position.halfMoveCounter >= 100) return true;
    //std::cout << "Stalemate" << std::endl;
    return isStaleMate();
}

bool Engine::isRepetition() {
    int i = std::min(position.ply() - 1,
                     position.halfMoveCounter); //TODO: instead of ply use moveCounter which resets every capture
    if (position.ply() >= 4) {
        int lastKey = position.history[position.ply() - 1].entry;
        int rep = 0;
        for (int x = 4; x <= i; x += 2) {
            int k = position.history[position.ply() - x - 1].entry;
            if (k == lastKey && ++rep >= 2) {
                return true;
            }
        }
    }
    return false;
}

bool Engine::isInsufficientMaterial() {
    bool result = false;
    unsigned long long pawns = position.bitboard_of(Piece::WHITE_PAWN) |
                               position.bitboard_of(Piece::BLACK_PAWN);
    if (pawns == 0L) {
        if ((position.bitboard_of(Piece::WHITE_QUEEN) +
             position.bitboard_of(Piece::BLACK_QUEEN) +
             position.bitboard_of(Piece::WHITE_ROOK) +
             position.bitboard_of(Piece::BLACK_ROOK)) != 0L) {
            result = false;
        } else {
            std::bitset<64> bs(position.all_pieces<Color::WHITE>() | position.all_pieces<Color::BLACK>());
            long count = bs.count();
            if (count == 4) {
                if (std::bitset<64>(position.all_pieces<Color::WHITE>()).count() > 1 &&
                    std::bitset<64>(position.all_pieces<Color::BLACK>()).count() > 1) {
                    result = true;
                } else if (std::bitset<64>(position.bitboard_of(WHITE_KNIGHT)).count() == 2 ||
                           std::bitset<64>(position.bitboard_of(BLACK_KNIGHT)).count() == 2) {
                    result = true;
                }
            } else if (count < 4) {
                return true;
            }
        }
    }

    return result;
}

bool Engine::isStaleMate() {
    if (position.turn() == 0) {
        if (!position.in_check<WHITE>()) {
            MoveList<WHITE> moveList(position);
            if (moveList.size() == 0) {
                std::cout << "Stalemate" << std::endl;
                return true;
            }
        }
        return false;
    } else {
        if (!position.in_check<BLACK>()) {
            MoveList<BLACK> moveList(position);
            if (moveList.size() == 0) {
                return true;
            }
        }
        return false;
    }

    return false;
}

bool Engine::isCheckMate() { //TODO: make sideToPlay public/ getter?
    if (position.turn() == 0) {
        if (position.in_check<WHITE>()) {
            MoveList<WHITE> moveList(position);
            if (moveList.size() == 0) {
                return true;
            }
        }
        return false;
    } else {
        if (position.in_check<BLACK>()) {
            MoveList<BLACK> moveList(position);
            if (moveList.size() == 0) {
                return true;
            }
        }
        return false;
    }
}

int Engine::search() {
    int x = 0;
    int depth = 1;
    int ni = -999999999;
    int pi = 999999999;
    start = std::chrono::high_resolution_clock::now();
    while (depth <= 8) {
        if (position.turn() == 0) {
            x = negamax<WHITE>(&position, depth, ni, pi, true);
            //position.play<WHITE>(bestMove);
        } else {
            x = negamax<BLACK>(&position, depth, ni, pi, true);
            //position.play<BLACK>(bestMove);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        // Check if the time taken has exceeded the time control
        if (elapsed.count() > timeControl) {
            auto entry = tt.lookup(position.get_hash());
            if (entry != nullptr) {
                // Use the PV move stored in the transposition table
                bestMove = pvTable.lookup(position.get_hash());
            }
            break;
        }
        std::vector<Move> pvLine = getPVLine(position);
        std::cout << "info depth " << depth << " score cp " << x << " tt " << tt.size() << " time " << elapsed.count() << " nodes " << counter << " pv ";
        for (auto move: pvLine) {
            std::cout << move << " ";
        }
        std::cout << std::endl;

//        if (position.turn() == 0) {
//            MoveList<WHITE> moveList(position);
//            moveList.sort(&position, &pvTable);
//            //print moveList
//            std::cout << "moves:";
//            for (Move move: moveList) {
//                std::cout << move << " ";
//            }
//            std::cout << std::endl;
//        } else {
//            MoveList<BLACK> moveList(position);
//            moveList.sort(&position, &pvTable);
//            //print moveList
//            std::cout << "moves:";
//            for (Move move: moveList) {
//                std::cout << move << " ";
//            }
//            std::cout << std::endl;
//        }

        depth++;
    }

    bestMove = pvTable.lookup(position.get_hash());
    if (position.turn() == 0) {
        position.play<WHITE>(bestMove);
    } else {
        position.play<BLACK>(bestMove);
    }
    std::cout << "Depth: " << depth << std::endl;
    std::vector<Move> pvLine = getPVLine(position);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "info depth " << depth << " score cp " << x << " tt " << tt.size() << " time " << elapsed.count() << " nodes " << counter << " pv ";
    for (auto move: pvLine) {
        std::cout << move << " ";
    }
    std::cout << std::endl;
    return x;
}

void Engine::getCaptures() {
    std::cout << "Captures White: ";
    CaptureList<WHITE> moves(position);
    for (Move move: moves) {
        std::cout << move << "-";
        std::cout << move.flags() << " ";
    }
    std::cout << std::endl;
    std::cout << "Captures Black: ";
    CaptureList<BLACK> moves2(position);
    for (Move move: moves2) {
        std::cout << move << "-";
        std::cout << move.flags() << " ";
    }
    std::cout << std::endl;
}

void Engine::getMoves() {
    std::cout << "Moves White: ";
    MoveList<WHITE> moves(position);
    for (Move move: moves) {
        std::cout << move << " ";
    }
    std::cout << std::endl;
    std::cout << "Moves Black: ";
    MoveList<BLACK> moves2(position);
    for (Move move: moves2) {
        std::cout << move << " ";
    }
    std::cout << std::endl;
}

void Engine::info() {
    std::cout << "Turn: " << position.turn() << std::endl;
    std::cout << "Ply: " << position.ply() << std::endl;
    std::cout << "HalfMoveCounter: " << position.halfMoveCounter << std::endl;
    std::cout << "TT size: " << tt.size() << std::endl;
}

std::vector<Move> Engine::getPVLine(Position& pos) {
    std::vector<Move> pvLine;
    while (true) {
        Move pvMove = pvTable.lookup(pos.get_hash());
        if (pvMove == Move()) {
            break;
        }
        pvLine.push_back(pvMove);
        if (pos.turn() == 0) {
            pos.play<WHITE>(pvMove);
        } else {
            pos.play<BLACK>(pvMove);
        }
    }
    // Loop through the PV line and undo the moves
    for (int i = pvLine.size() - 1; i >= 0; i--) {
        if (pos.turn() == 0) {
            pos.undo<BLACK>(pvLine[i]);
        } else {
            pos.undo<WHITE>(pvLine[i]);
        }
    }
    return pvLine;
}

