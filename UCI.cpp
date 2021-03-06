//
// Created by LociStar on 29.09.2020.
//
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "UCI.h"

bool startsWith(std::string mainStr, std::string toMatch) {
    // std::string::find returns 0 if toMatch is found at starting
    if (mainStr.find(toMatch) == 0)
        return true;
    else
        return false;
}

void UCI::uciCommunication() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if ("uci" == input) {
            inputUCI();
        } else if (startsWith(input, "setoption")) {
            inputSetOption(input);
        } else if (input == "isready") {
            inputIsReady();
        } else if (input == "ucinewgame") {
            inputUCINewGame();
        } else if (startsWith(input, "position")) {
            inputPosition(input);
        } else if (startsWith(input, "go")) {
            inputGo(input);
        } else if (input == "print") {
            inputPrint();
        } else if (input == "quit") {
            inputQuit(input);
            break;
        } else if (input == "stop") {
            //MoveList legalMoves = MoveGenerator.generateLegalMoves(board);
        }
    }

}

void UCI::inputUCI() {
    std::cout << "id name " << ENGINENAME << std::endl;
    std::cout << "id author LociStar" << std::endl;
    //options go here
    std::cout << "uciok" << std::endl;
}

void UCI::inputSetOption(std::string input) {
    //set options
}

void UCI::inputIsReady() {
    std::cout << "readyok" << std::endl;
}

void UCI::inputUCINewGame() {
    delete engine;
    engine = new Engine();
    initialise_all_databases();
    zobrist::initialise_zobrist_keys();
    //Position::set("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", engine->position);
    newGame = true;
}

void UCI::inputQuit(std::string input) {
    delete engine;
    exit(0);
}

void UCI::inputPosition(std::string input) {
    //std::fill_n(engine->position.history,256, UndoInfo());
    //std::cout << engine->position << std::endl;
    input.erase(0, 9);
    if (startsWith(input, "startpos")) {
        input.erase(0, 9);
        if (newGame) {
            Position::set("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", engine->position);
            newGame = false;
        }
    } else if (startsWith(input, "fen")) {
        input.erase(0, 4);
        if (newGame) {
            Position::set(input, engine->position);
            newGame = false;
        }
    }

    if (startsWith(input, "moves")) {
        //std::cout << engine->position;
        input.erase(0, 6);
        //split string at whitespaces
        std::vector<std::string> result;
        std::istringstream iss(input);
        for (std::string s; iss >> s;)
            result.push_back(s);
        Move *move = nullptr;
        if (false) {
            for (auto &item : result) {
                //if (engine->position.history[engine->position.ply()].epsq == )
                std::cout << "LOOP" << item << std::endl;
                move = new Move(item);
                //generate MoveList for validation

                if (engine->position.turn() == 0) {
                    MoveList<WHITE> moveList1(engine->position);
                    for (Move legalMove : moveList1) {
                        //move validation check
                        if (legalMove.from() == move->from() && legalMove.to() == move->to()) {
                            std::cout << "Input White: " << move->from() << move->to() << std::endl;
                            engine->position.play<WHITE>(legalMove);
                        }
                    }
                } else {
                    MoveList<BLACK> moveList2(engine->position);
                    for (Move legalMove : moveList2) {
                        std::cout << "Black: " << legalMove << std::endl;
                        //move validation check
                        if (legalMove.from() == move->from() && legalMove.to() == move->to()) {
                            std::cout << "Input Black: " << move->from() << move->to() << std::endl;
                            engine->position.play<BLACK>(legalMove);
                        }
                    }
                }
                move = nullptr;
            }
            newGame = true;
        } else {
            move = new Move(result[result.size() - 1]);
            if (engine->position.turn() == 0) {
                MoveList<WHITE> moveList3(engine->position);
                for (Move legalMove: moveList3) {
                    //move validation check
                    if (legalMove.from() == move->from() && legalMove.to() == move->to()) {
                        //std::cout << legalMove;
                        engine->position.play<WHITE>(legalMove);
                    }
                }
            } else {
                MoveList<BLACK> moveList4(engine->position);
                for (Move legalMove: moveList4) {
                    //move validation check
                    if (legalMove.from() == move->from() && legalMove.to() == move->to()) {
                        engine->position.play<BLACK>(legalMove);
                    }
                }
            }
            move = new Move(result.back());
        }
        delete move;
    }
}

void UCI::inputGo(std::string input) {
    engine->search();
    std::cout << "\nbestmove " << engine->bestMove << std::endl;
}

void UCI::inputPrint() {
    std::cout << engine->position << std::endl;
    if (engine->position.turn() == 0) std::cout << engine->evaluation() << std::endl;
    else std::cout << engine->evaluation() << std::endl;
    std::cout << "Side: " << engine->position.turn() << std::endl;
    std::cout << "Draw: " << engine->isDraw() << std::endl;

    /*MoveList<WHITE> moveList3(engine->position);
    for (Move legalMove: moveList3) {
        std::cout << legalMove;
    }
    std::cout << std::endl;*/



}
