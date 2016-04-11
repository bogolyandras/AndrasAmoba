#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "position.h"
#include "field.h"

class AiPlayer
{
public:
    AiPlayer();
    virtual ~AiPlayer();
    virtual Position place(Field* board, int sizeX, int sizeY) = 0;
};

#endif // AIPLAYER_H
