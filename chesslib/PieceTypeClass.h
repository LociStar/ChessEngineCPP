//
// Created by LociStar on 28.09.2020.
//

#ifndef CHESSENGINE_PIECETYPECLASS_H
#define CHESSENGINE_PIECETYPECLASS_H


#include <string>
#include <map>


class PieceTypeClass {
public:
    enum PieceType {
        /**
     * Pawn piece type.
     */
        PAWN,
        /**
         * Knight piece type.
         */
        KNIGHT,
        /**
         * Bishop piece type.
         */
        BISHOP,
        /**
         * Rook piece type.
         */
        ROOK,
        /**
         * Queen piece type.
         */
        QUEEN,
        /**
         * King piece type.
         */
        KING,
        /**
         * None piece type.
         */
        NONE
    };

    static PieceType fromValue(std::string v);

private:
    std::map<std::string, PieceType> mapPieceType = {{"King":KING}}

};


#endif //CHESSENGINE_PIECETYPECLASS_H
