#include "randomaiplayer.h"
#include <vector>
#include <cstdlib>

RandomAIPlayer::RandomAIPlayer()
{

}

RandomAIPlayer::~RandomAIPlayer()
{

}

Position RandomAIPlayer::place(Field *board, int sizeX, int sizeY)
{
    std::vector<Position> possiblePositions;
    for (int i = 0; i < sizeX * sizeY; ++i) {
        if (board[i] == Field::Empty) {
            possiblePositions.push_back(Position::TranslatePosition(i, sizeX, sizeY));
        }
    }
    if (possiblePositions.size() != 0) {
        return possiblePositions.at(std::rand()%possiblePositions.size());
    }
    return Position(0, 0);
}
