#include "advantage.h"

Advantage::Advantage(Position position, Threat OpponentThreatDecrease, Threat PlayerThreatInscrease) :
    position(position),
    OpponentThreatDecrease(OpponentThreatDecrease),
    PlayerThreatInscrease(PlayerThreatInscrease)
{

}

bool Advantage::operator>(const Advantage &otherAdvantage) const
{
    if (this->PlayerThreatInscrease.Threat0 > otherAdvantage.PlayerThreatInscrease.Threat0) {
        return true;
    } else if (this->PlayerThreatInscrease.Threat0 < otherAdvantage.PlayerThreatInscrease.Threat0) {
        return false;
    } else {
        return false;
    }
}

bool Advantage::operator<(const Advantage &otherAdvantage) const
{
    return !(*this>otherAdvantage);
}
