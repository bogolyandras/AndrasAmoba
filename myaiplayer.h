#ifndef MYAIPLAYER_H
#define MYAIPLAYER_H
#include "aiplayer.h"
#include "threat.h"
#include "advantage.h"

class MyAiPlayer : public AiPlayer
{
public:
    MyAiPlayer();
    ~MyAiPlayer();
    Position place(Field* board, int sizeX, int sizeY);
private:
    int sizeX, sizeY;
    Field* BoardData;
    Threat getThreatForPlayer(Field playerField);
    std::vector<Advantage> PlacementAdvantages;
    void ReduceAttackSteps(unsigned char level);
    void ReduceDefenseSteps(unsigned char level);
};

#endif // MYAIPLAYER_H
