#ifndef MYAIPLAYER_H
#define MYAIPLAYER_H
#include "aiplayer.h"

class MyaAiPlayer : public AiPlayer
{
public:
    MyaAiPlayer();
    ~MyaAiPlayer();
    Position place(Field* board, int sizeX, int sizeY);
};

#endif // MYAIPLAYER_H
