#include <vector>
#include "myaiplayer.h"


MyAiPlayer::MyAiPlayer() : sizeX(0), sizeY(0), BoardData(nullptr), PlacementAdvantages()
{

}

MyAiPlayer::~MyAiPlayer()
{

}

Position MyAiPlayer::place(Field *board, int sizeX, int sizeY)
{
    this->BoardData = board;
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    PlacementAdvantages.clear();

    Threat StartOpponentThreat = getThreatForPlayer(Field::X);
    Threat StartPlayerThreat = getThreatForPlayer(Field::O);

    //Iterate over all possible steps
    for (int i = 0; i < sizeX * sizeY; ++i) {
        Position p = Position::TranslatePosition(i, sizeX, sizeY);

        //Is it possible to place something here?
        if (BoardData[i] != Field::Empty)
            continue;

        //Place our mark here
        BoardData[i] = Field::O;

        //Count the advantage the step
        Advantage a(p,
                    StartOpponentThreat - getThreatForPlayer(Field::X),
                    getThreatForPlayer(Field::O) - StartPlayerThreat);
        PlacementAdvantages.push_back(a);

        //Remove the placement
        BoardData[i] = Field::Empty;
    }

    ReduceAttackSteps(6);
    ReduceDefenseSteps(5);
    ReduceAttackSteps(5);
    ReduceDefenseSteps(4);
    ReduceAttackSteps(4);
    ReduceDefenseSteps(3);
    ReduceAttackSteps(3);
    ReduceDefenseSteps(2);
    ReduceAttackSteps(2);
    ReduceDefenseSteps(1);
    ReduceAttackSteps(1);

    return PlacementAdvantages.at(0).position;
}

Threat MyAiPlayer::getThreatForPlayer(Field lookingFor)
{
    int PossibilitiesRight[sizeX * sizeY];
    int PossibilitiesRightBottom[sizeX * sizeY];
    int PossibilitiesBottom[sizeX * sizeY];
    int PossibilitiesLeftBottom[sizeX * sizeY];

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
        if (p.X + 5 <= sizeX) {
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

        /*
         * X
         *  X
         *   X
         *    X
         *     X
         */
        PossibilitiesRightBottom[i] = 0;
        if (p.X + 5 <= sizeX && p.Y + 5 <= sizeY) {
            int ThreatCount = 1;
            for (int j = 0; j < 5; ++j) {
                Position p2 = p;
                p2.X += j;
                p2.Y += j;
                Field currentField = BoardData[Position::TranslatePosition(p2, sizeX, sizeY)];
                if (currentField == lookingFor) {
                    ThreatCount++;
                } else if(currentField != Field::Empty) {
                    ThreatCount = 0;
                    break;
                }
            }
            PossibilitiesRightBottom[i] = ThreatCount;
        }

        /*
         * X
         * X
         * X
         * X
         * X
         */
        PossibilitiesBottom[i] = 0;
        if (p.Y + 5 <= sizeY) {
            int ThreatCount = 1;
            for (int j = 0; j < 5; ++j) {
                Position p2 = p;
                p2.Y += j;
                Field currentField = BoardData[Position::TranslatePosition(p2, sizeX, sizeY)];
                if (currentField == lookingFor) {
                    ThreatCount++;
                } else if(currentField != Field::Empty) {
                    ThreatCount = 0;
                    break;
                }
            }
            PossibilitiesBottom[i] = ThreatCount;
        }

        /*
         *     X
         *    X
         *   X
         *  X
         * X
         */
        PossibilitiesLeftBottom[i] = 0;
        if (p.X - 4 >= 0 && p.Y + 5 <= sizeY) {
            int ThreatCount = 1;
            for (int j = 0; j < 5; ++j) {
                Position p2 = p;
                p2.X -= j;
                p2.Y += j;
                Field currentField = BoardData[Position::TranslatePosition(p2, sizeX, sizeY)];
                if (currentField == lookingFor) {
                    ThreatCount++;
                } else if(currentField != Field::Empty) {
                    ThreatCount = 0;
                    break;
                }
            }
            PossibilitiesLeftBottom[i] = ThreatCount;
        }
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
        switch (PossibilitiesBottom[i])
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

void MyAiPlayer::ReduceAttackSteps(unsigned char level)
{
    int Max = 0;
    for (std::vector<Advantage>::iterator it = PlacementAdvantages.begin(); it != PlacementAdvantages.end(); ++it) {
        if(level == 6) {
            if ((*it).PlayerThreatIncrease.Threat5 > Max)
                Max = (*it).PlayerThreatIncrease.Threat5;
        } else if(level == 5) {
            if ((*it).PlayerThreatIncrease.Threat4 > Max)
                Max = (*it).PlayerThreatIncrease.Threat4;
        } else if(level == 4) {
            if ((*it).PlayerThreatIncrease.Threat3 > Max)
                Max = (*it).PlayerThreatIncrease.Threat3;
        } else if(level == 3) {
            if ((*it).PlayerThreatIncrease.Threat2 > Max)
                Max = (*it).PlayerThreatIncrease.Threat2;
        } else if(level == 2) {
            if ((*it).PlayerThreatIncrease.Threat1 > Max)
                Max = (*it).PlayerThreatIncrease.Threat1;
        } else if(level == 1) {
            if ((*it).PlayerThreatIncrease.Threat0 > Max)
                Max = (*it).PlayerThreatIncrease.Threat0;
        }
    }

    if (Max == 0)
        return;

    for (std::vector<Advantage>::iterator it = PlacementAdvantages.begin(); it != PlacementAdvantages.end();) {
      if (    (level == 6 && (*it).PlayerThreatIncrease.Threat5 < Max) ||
              (level == 5 && (*it).PlayerThreatIncrease.Threat4 < Max) ||
              (level == 4 && (*it).PlayerThreatIncrease.Threat3 < Max) ||
              (level == 3 && (*it).PlayerThreatIncrease.Threat2 < Max) ||
              (level == 2 && (*it).PlayerThreatIncrease.Threat1 < Max) ||
              (level == 1 && (*it).PlayerThreatIncrease.Threat0 < Max)
            ) {
        it = PlacementAdvantages.erase(it);
      } else {
        ++it;
      }
    }
}

void MyAiPlayer::ReduceDefenseSteps(unsigned char level)
{
    int Max = 0;
    for (std::vector<Advantage>::iterator it = PlacementAdvantages.begin(); it != PlacementAdvantages.end(); ++it) {
        if(level == 6) {
            if ((*it).OpponentThreatDecrease.Threat5 > Max)
                Max = (*it).OpponentThreatDecrease.Threat5;
        } else if(level == 5) {
            if ((*it).OpponentThreatDecrease.Threat4 > Max)
                Max = (*it).OpponentThreatDecrease.Threat4;
        } else if(level == 4) {
            if ((*it).OpponentThreatDecrease.Threat3 > Max)
                Max = (*it).OpponentThreatDecrease.Threat3;
        } else if(level == 3) {
            if ((*it).OpponentThreatDecrease.Threat2 > Max)
                Max = (*it).OpponentThreatDecrease.Threat2;
        } else if(level == 2) {
            if ((*it).OpponentThreatDecrease.Threat1 > Max)
                Max = (*it).OpponentThreatDecrease.Threat1;
        } else if(level == 1) {
            if ((*it).OpponentThreatDecrease.Threat0 > Max)
                Max = (*it).OpponentThreatDecrease.Threat0;
        }
    }

    if (Max == 0)
        return;

    for (std::vector<Advantage>::iterator it = PlacementAdvantages.begin(); it != PlacementAdvantages.end();) {
      if (    (level == 6 && (*it).OpponentThreatDecrease.Threat5 < Max) ||
              (level == 5 && (*it).OpponentThreatDecrease.Threat4 < Max) ||
              (level == 4 && (*it).OpponentThreatDecrease.Threat3 < Max) ||
              (level == 3 && (*it).OpponentThreatDecrease.Threat2 < Max) ||
              (level == 2 && (*it).OpponentThreatDecrease.Threat1 < Max) ||
              (level == 1 && (*it).OpponentThreatDecrease.Threat0 < Max)
            ) {
        it = PlacementAdvantages.erase(it);
      } else {
        ++it;
      }
    }
}
