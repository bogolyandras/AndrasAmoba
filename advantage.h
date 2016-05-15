#ifndef ADVANTAGE_H
#define ADVANTAGE_H
#include "position.h"
#include "threat.h"

class Advantage
{
public:
    Advantage(Position position, Threat OpponentThreatDecrease, Threat PlayerThreatIncrease);
    Position position;
    Threat OpponentThreatDecrease;
    Threat PlayerThreatIncrease;
};

#endif // ADVANTAGE_H
