//
// Created by LociStar on 28.09.2020.
//

#include "engine.h"
#include <bitset>
#include "positionTables.h"

template<Color Us>
int Engine::negamax(Position *p, int depth, int alpha, int beta, bool first) {
    //int localalpha = alpha;

    //tableNode tableNode = transposition.get(key);
    counter++;

    int move_score = 0;
    if (depth == 0) {
        //move_score = quiescenceSearch(alpha, beta);
        //evaluation_2<Us>();
        return evaluation();
    }

    int best_score = -999999999; // Negative-Infinity
    MoveList<Us> moveList(*p);

    //sortMoves(moveList, key);2020-09-30 12:07:43,585-->1:position startpos moves b1a3 b8a6 g1f3 g8f6 a1b1 a8b8 h1g1 h8g8
    if (isDraw()) {
        return 0;
    }
    if (isCheckMate()) {
        return -9000 * depth;
    }

    for (Move move : moveList) {
        p->play<Us>(move);
        move_score = -negamax<~Us>(p, depth - 1, -beta, -alpha, false);
        p->undo<Us>(move);

        if (move_score > best_score) {
            best_score = move_score;
            if (first) {
                bestMove = move;
            }
        }
        alpha = std::max(alpha, best_score);
        if (alpha >= beta) {
            break;
        }
    }

    //addTransposition(key, depth, alphaOriginal, beta, move_score, best);

    return best_score;
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
    int depth = 6;
    int ni = -999999999;
    int pi = 999999999;
    bool f = true;
    if (position.turn() == 0) {
        x = negamax<WHITE>(&position, depth, ni, pi, f);
        MoveList<WHITE> moves(position);
        for (Move move : moves) {
            std::cout << move << " ";
        }
        position.play<WHITE>(bestMove);
    } else {
        x = negamax<BLACK>(&position, depth, ni, pi, f);
        MoveList<BLACK> moves(position);
        for (Move move : moves) {
            std::cout << move << " ";
        }
        position.play<BLACK>(bestMove);
    }
    return x;
}
