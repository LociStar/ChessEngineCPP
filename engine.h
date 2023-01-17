//
// Created by LociStar on 28.09.2020.
//

#ifndef CHESSENGINE_ENGINE_H
#define CHESSENGINE_ENGINE_H

#include <chrono>
#include "src/position.h"
#include "src/transpositionTable.h"
#include "src/pvTable.h"

class Engine {
private:
    const std::string ENGINENAME = "LociStarBot";
public:
    Position position;
    Move bestMove;
    int counter;
    int timeControl = 600000;
    std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::duration<int64_t, std::ratio<1, 1000000000>>> start;

    TranspositionTable tt = TranspositionTable();
    PVTable pvTable = PVTable();

    int evaluation();
    //template<Color Us>
    //int evaluation_2();
    bool isDraw();
    bool isCheckMate();

    template<Color Us>
    int negamax(Position* pos, int depth, int alpha, int beta, bool first);

    int search();

    void getCaptures();
    void getMoves();

    void info();

private:

    bool isRepetition();
    bool isInsufficientMaterial();
    bool isStaleMate();

    template<Color Us>
    int quiescenceSearch(Position *pos, int alpha, int beta, int depth);

    std::vector<Move> getPVLine(Position &pos);
};


#endif //CHESSENGINE_ENGINE_H
