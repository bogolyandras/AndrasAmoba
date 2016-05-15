#ifndef ADVANTAGE_H
#define ADVANTAGE_H
#include "position.h"
#include "threat.h"

class Advantage
{
public:
    Advantage(Position position, Threat OpponentThreatDecrease, Threat PlayerThreatInscrease);
    Position position;
    Threat OpponentThreatDecrease;
    Threat PlayerThreatInscrease;
    bool operator>(const Advantage& otherAdvantage) const;
    bool operator<(const Advantage& otherAdvantage) const;
};

#endif // ADVANTAGE_H
