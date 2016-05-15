#include "myaiplayer.h"

MyaAiPlayer::MyaAiPlayer() : sizeX(0), sizeY(0), BoardData(nullptr)
{

}

MyaAiPlayer::~MyaAiPlayer()
{

}

Position MyaAiPlayer::place(Field *board, int sizeX, int sizeY)
{
    this->BoardData = board;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

Threat MyaAiPlayer::getThreatForPlayer(Field lookingFor)
{
    unsigned char PossibilitiesRight[sizeX * sizeY];
    unsigned char PossibilitiesRightBottom[sizeX * sizeY];
    unsigned char PossibilitiesLeft[sizeX * sizeY];
    unsigned char PossibilitiesLeftBottom[sizeX * sizeY];

    for (int i = 0; i < sizeX * sizeY; ++i) {
        Position p = Position::TranslatePosition(i, sizeX, sizeY);

        /*
         * XXXXX
         *
         *
         *
         *
         */
        PossibilitiesRight[i] = 0;
        if (p.X + 4 < sizeX) {
            int ThreatCount = 1;
            for (int j = 0; j < 5; ++j) {
                Position p2 = p;
                p2.X += j;
                Field currentField = BoardData[Position::TranslatePosition(p2, sizeX, sizeY)];
                if (currentField == lookingFor) {
                    ThreatCount++;
                } else if(currentField != Field::Empty) {
                    ThreatCount = 0;
                    break;
                }
            }
            PossibilitiesRight[i] = ThreatCount;
        }

        PossibilitiesRightBottom[i] = 0;
        PossibilitiesLeft[i] = 0;
        PossibilitiesLeftBottom[i] = 0;

    }

    Threat threats;

    for (int i = 0; i < sizeX * sizeY; ++i) {
        switch (PossibilitiesRight[i])
        {
        case 6:
            threats.Threat5++;
        case 5:
            threats.Threat4++;
        case 4:
            threats.Threat3++;
        case 3:
            threats.Threat2++;
        case 2:
            threats.Threat1++;
        case 1:
            threats.Threat0++;
            break;
        }
        switch (PossibilitiesRightBottom[i])
        {
        case 6:
            threats.Threat5++;
        case 5:
            threats.Threat4++;
        case 4:
            threats.Threat3++;
        case 3:
            threats.Threat2++;
        case 2:
            threats.Threat1++;
        case 1:
            threats.Threat0++;
            break;
        }
        switch (PossibilitiesLeft[i])
        {
        case 6:
            threats.Threat5++;
        case 5:
            threats.Threat4++;
        case 4:
            threats.Threat3++;
        case 3:
            threats.Threat2++;
        case 2:
            threats.Threat1++;
        case 1:
            threats.Threat0++;
            break;
        }
        switch (PossibilitiesLeftBottom[i])
        {
        case 6:
            threats.Threat5++;
        case 5:
            threats.Threat4++;
        case 4:
            threats.Threat3++;
        case 3:
            threats.Threat2++;
        case 2:
            threats.Threat1++;
        case 1:
            threats.Threat0++;
            break;
        }
    }

    return threats;
}
