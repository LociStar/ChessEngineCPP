#include <iostream>
#include <chrono>

#include "src/position.h"
#include "src/tables.h"
#include "src/types.h"
#include "engine.h"
#include "UCI.h"

template<Color Us>
unsigned long long perft(Position &p, unsigned int depth) {
    int nmoves;
    unsigned long long nodes = 0;

    MoveList<Us> list(p);

    if (depth == 1) return (unsigned long long) list.size();

    for (Move move : list) {
        p.play<Us>(move);
        nodes += perft<~Us>(p, depth - 1);
        p.undo<Us>(move);
    }

    return nodes;
}

void test_perft_this() {
    Position p;
    Position::set("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", p);
    std::cout << p;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto n = perft<WHITE>(p, 5);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    auto diff = end - begin;

    std::cout << "Nodes: " << n << "\n";
    std::cout << "NPS: "
              << int(n * 1000000.0 / std::chrono::duration_cast<std::chrono::microseconds>(diff).count())
              << "\n";
    std::cout << "Time difference = "
              << std::chrono::duration_cast<std::chrono::microseconds>(diff).count() << " [microseconds]\n";
}

int main() {
    //initialise_all_databases();
    //zobrist::initialise_zobrist_keys();
    /*MyList<MyNode<Move>> moves;
    Move move(Square::NO_SQUARE, Square::NO_SQUARE);
    moves.push(new MyNode<Move>(move));
    std::cout << moves.size() << std::endl;*/
    //Position p;
    //Position::set("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -", p);

    //p.move_piece(Square::a2, Square::a4);
    //std::cout << p;



    /*MoveList<WHITE> list(p);

    for(Move m : list) {
        std::cout << m << "\n";
    }
    std::cout << list.size() << std::endl;
    std::cout << p.ply() << std::endl;*/

    //test_perft_this();

    /*Engine engine;
    //needs at least one node (Null Move)
    Position::set("r1bqkbnr/pppppppp/8/8/3P4/P1N1B3/1PP1PPPP/2RQKBNR b Kkq - 0 5 ", engine.position);//position startpos moves d2d4 b8a6 b1c3 a6b4 a2a3 b4a2 c1e3 a2c1 a1c1
    std::cout << engine.position;
    //engine.position.play<WHITE>(move1);
    //if(engine.isCheckMate()) return 0;
    //std::cout << engine.position << std::endl;
    //MoveList<WHITE> moveList(engine.position);
    *//*for(Move m : moveList) {
        std::cout << m << "\n";
    }*//*
    int x = engine.search();
    std::cout << "bestmove " << engine.bestMove << std::endl;*/
    UCI uci;
    uci.uciCommunication();
    //test_perft_this();

    return 0;
}