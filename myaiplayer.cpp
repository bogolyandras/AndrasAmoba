#include "myaiplayer.h"

MyaAiPlayer::MyaAiPlayer() : sizeX(0), sizeY(0), BoardData(nullptr)
{

}

MyaAiPlayer::~MyaAiPlayer()
{

}

Position MyaAiPlayer::place(Field *board, int sizeX, int sizeY)
{
    this->BoardData = board;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

Threat MyaAiPlayer::getThreatForPlayer(Field playerField)
{

}
