//
// Created by LociStar on 28.09.2020.
//

#ifndef CHESSENGINE_ENGINE_H
#define CHESSENGINE_ENGINE_H

#include "src/position.h"

class Engine {
private:
    const std::string ENGINENAME = "LociStarBot";
public:
    Position position;
    Move bestMove;
    int counter;

    int evaluation();
    //template<Color Us>
    //int evaluation_2();
    bool isDraw();
    bool isCheckMate();

    template<Color Us>
    int negamax(Position* p, int depth, int alpha, int beta, bool first);

    int search();

private:

    bool isRepetition();
    bool isInsufficientMaterial();
    bool isStaleMate();

};


#endif //CHESSENGINE_ENGINE_H
