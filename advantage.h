#ifndef ADVANTAGE_H
#define ADVANTAGE_H
#include "position.h"
#include "threat.h"

class Advantage
{
public:
    Advantage();
    Position position;
    Threat OpponentThreatDecrease;
    Threat PlayerThreatInscrease;
};

#endif // ADVANTAGE_H
