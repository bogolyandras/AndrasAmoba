#ifndef THREAT_H
#define THREAT_H


class Threat
{
public:
    Threat();
    int Threat0;
    int Threat1;
    int Threat2;
    int Threat3;
    int Threat4;
    int Threat5;
    Threat &operator+=(const Threat &otherThreat);
    Threat &operator-=(const Threat &otherThreat);
    Threat operator+(const Threat &otherThreat) const;
    Threat operator-(const Threat &otherThreat) const;
};

#endif // THREAT_H
