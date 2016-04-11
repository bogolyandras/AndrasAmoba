#ifndef RANDOMAIPLAYER_H
#define RANDOMAIPLAYER_H
#include "aiplayer.h"

class RandomAIPlayer : public AiPlayer
{
public:
    RandomAIPlayer();
    ~RandomAIPlayer();
    Position place(Field* board, int sizeX, int sizeY);
};

#endif // RANDOMAIPLAYER_H
