//
// Created by LociStar on 29.09.2020.
//

#ifndef CHESSENGINE_UCI_H
#define CHESSENGINE_UCI_H


#include "engine.h"

class UCI {
public:
    const std::string ENGINENAME = "LociStarBot";

    void uciCommunication();

private:
    Engine *engine = new Engine;
    bool newGame = false;

    void inputUCI();

    void inputSetOption(std::string input);

    void inputIsReady();

    void inputUCINewGame();

    void inputPosition(std::string input);

    void inputGo(std::string input);

    void inputPrint();

    void inputQuit(std::string input);

    void test(std::string input);
};


#endif //CHESSENGINE_UCI_H
