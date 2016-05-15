#include "advantage.h"

Advantage::Advantage(Position position, Threat OpponentThreatDecrease, Threat PlayerThreatIncrease) :
    position(position),
    OpponentThreatDecrease(OpponentThreatDecrease),
    PlayerThreatIncrease(PlayerThreatIncrease)
{

}

bool Advantage::operator>(const Advantage &otherAdvantage) const
{
    return (*this<otherAdvantage);
}

bool Advantage::operator<(const Advantage &otherAdvantage) const
{
    //Defense 5
    if (this->OpponentThreatDecrease.Threat5 > otherAdvantage.OpponentThreatDecrease.Threat5) {
        return true;
    } else if(this->OpponentThreatDecrease.Threat5 < otherAdvantage.OpponentThreatDecrease.Threat5) {
        return false;
    } else {
        // Attack 5
        if (this->PlayerThreatIncrease.Threat5 > otherAdvantage.PlayerThreatIncrease.Threat5) {
            return true;
        } else if (this->PlayerThreatIncrease.Threat5 < otherAdvantage.PlayerThreatIncrease.Threat5) {
            return false;
        } else {
            //Defense 4
            if (this->OpponentThreatDecrease.Threat4 > otherAdvantage.OpponentThreatDecrease.Threat4) {
                return true;
            } else if(this->OpponentThreatDecrease.Threat4 < otherAdvantage.OpponentThreatDecrease.Threat4) {
                return false;
            } else {
                //Attack 4
                if (this->PlayerThreatIncrease.Threat4 > otherAdvantage.PlayerThreatIncrease.Threat4) {
                    return true;
                } else if (this->PlayerThreatIncrease.Threat4 < otherAdvantage.PlayerThreatIncrease.Threat4) {
                    return false;
                } else {
                    //Defence 3
                    if (this->OpponentThreatDecrease.Threat3 > otherAdvantage.OpponentThreatDecrease.Threat3) {
                        return true;
                    } else if(this->OpponentThreatDecrease.Threat3 < otherAdvantage.OpponentThreatDecrease.Threat3) {
                        return false;
                    } else {
                        //Attack 3
                        if (this->PlayerThreatIncrease.Threat3 > otherAdvantage.PlayerThreatIncrease.Threat3) {
                            return true;
                        } else if (this->PlayerThreatIncrease.Threat3 < otherAdvantage.PlayerThreatIncrease.Threat3) {
                            return false;
                        } else {
                            //Defense 2
                            if (this->OpponentThreatDecrease.Threat2 > otherAdvantage.OpponentThreatDecrease.Threat2) {
                                return true;
                            } else if(this->OpponentThreatDecrease.Threat2 < otherAdvantage.OpponentThreatDecrease.Threat2) {
                                return false;
                            } else {
                                //Attack 2
                                if (this->PlayerThreatIncrease.Threat2 > otherAdvantage.PlayerThreatIncrease.Threat2) {
                                    return true;
                                } else if (this->PlayerThreatIncrease.Threat2 < otherAdvantage.PlayerThreatIncrease.Threat2) {
                                    return false;
                                } else {
                                    //Defense 1
                                    if (this->OpponentThreatDecrease.Threat1 > otherAdvantage.OpponentThreatDecrease.Threat1) {
                                        return true;
                                    } else if(this->OpponentThreatDecrease.Threat1 < otherAdvantage.OpponentThreatDecrease.Threat1) {
                                        return false;
                                    } else {
                                        //Attack 1
                                        if (this->PlayerThreatIncrease.Threat1 > otherAdvantage.PlayerThreatIncrease.Threat1) {
                                            return true;
                                        } else if (this->PlayerThreatIncrease.Threat1 < otherAdvantage.PlayerThreatIncrease.Threat1) {
                                            return false;
                                        } else {
                                            //Defense 0
                                            if (this->OpponentThreatDecrease.Threat0 > otherAdvantage.OpponentThreatDecrease.Threat0) {
                                                return true;
                                            } else if(this->OpponentThreatDecrease.Threat0 < otherAdvantage.OpponentThreatDecrease.Threat0) {
                                                return false;
                                            } else {
                                                //Attack 0
                                                if (this->PlayerThreatIncrease.Threat0 > otherAdvantage.PlayerThreatIncrease.Threat0) {
                                                    return true;
                                                } else if (this->PlayerThreatIncrease.Threat0 < otherAdvantage.PlayerThreatIncrease.Threat0) {
                                                    return false;
                                                } else {
                                                    return false;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
