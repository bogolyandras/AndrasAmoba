#ifndef THREAT_H
#define THREAT_H


class Threat
{
public:
    Threat();
    unsigned char Threat0;
    unsigned char Threat1;
    unsigned char Threat2;
    unsigned char Threat3;
    unsigned char Threat4;
    unsigned char Threat5;
    Threat &operator+=(const Threat &otherThreat);
    Threat &operator-=(const Threat &otherThreat);
    Threat operator+(const Threat &otherThreat) const;
    Threat operator-(const Threat &otherThreat) const;
};

#endif // THREAT_H
