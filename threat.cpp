#include "threat.h"

Threat::Threat() :
    Threat0(0), Threat1(0), Threat2(0), Threat3(0), Threat4(0), Threat5(0)
{

}

Threat &Threat::operator+=(const Threat &otherThreat)
{
    Threat0 += otherThreat.Threat0;
    Threat1 += otherThreat.Threat1;
    Threat2 += otherThreat.Threat2;
    Threat3 += otherThreat.Threat3;
    Threat4 += otherThreat.Threat4;
    Threat5 += otherThreat.Threat5;
    return *this;
}

Threat &Threat::operator-=(const Threat &otherThreat)
{
    Threat0 -= otherThreat.Threat0;
    Threat1 -= otherThreat.Threat1;
    Threat2 -= otherThreat.Threat2;
    Threat3 -= otherThreat.Threat3;
    Threat4 -= otherThreat.Threat4;
    Threat5 -= otherThreat.Threat5;
    return *this;
}

Threat Threat::operator+(const Threat &otherThreat) const
{
    Threat threat = *this;
    threat += otherThreat;
    return threat;
}

Threat Threat::operator-(const Threat &otherThreat) const
{
    Threat threat = *this;
    threat -= otherThreat;
    return threat;
}
