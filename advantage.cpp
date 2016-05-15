#include "advantage.h"

Advantage::Advantage(Position position, Threat OpponentThreatDecrease, Threat PlayerThreatIncrease) :
    position(position),
    OpponentThreatDecrease(OpponentThreatDecrease),
    PlayerThreatIncrease(PlayerThreatIncrease)
{

}

bool Advantage::operator>(const Advantage &otherAdvantage) const
{
    return true;
    /*if (this->PlayerThreatInscrease.Threat0 > otherAdvantage.PlayerThreatInscrease.Threat0) {
        return true;
    } else if (this->PlayerThreatInscrease.Threat0 < otherAdvantage.PlayerThreatInscrease.Threat0) {
        return false;
    } else {
        return false;
    }*/
}

bool Advantage::operator<(const Advantage &otherAdvantage) const
{
    return false;
}
