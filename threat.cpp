#include "threat.h"

Threat::Threat() :
    Threat0(0), Threat1(0), Threat2(0), Threat3(0), Threat4(0), Threat5(0)
{

}

Threat Threat::operator+(const Threat &otherThreat) const
{
    Threat threat;
    threat.Threat0 = this->Threat0 + otherThreat.Threat0;
    threat.Threat1 = this->Threat1 + otherThreat.Threat1;
    threat.Threat2 = this->Threat2 + otherThreat.Threat2;
    threat.Threat3 = this->Threat3 + otherThreat.Threat3;
    threat.Threat4 = this->Threat4 + otherThreat.Threat4;
    threat.Threat5 = this->Threat5 + otherThreat.Threat5;
    return threat;
}

Threat Threat::operator-(const Threat &otherThreat) const
{
    Threat threat;
    threat.Threat0 = this->Threat0 - otherThreat.Threat0;
    threat.Threat1 = this->Threat1 - otherThreat.Threat1;
    threat.Threat2 = this->Threat2 - otherThreat.Threat2;
    threat.Threat3 = this->Threat3 - otherThreat.Threat3;
    threat.Threat4 = this->Threat4 - otherThreat.Threat4;
    threat.Threat5 = this->Threat5 - otherThreat.Threat5;
    return threat;
}
