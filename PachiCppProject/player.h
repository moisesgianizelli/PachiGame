#ifndef PLAYER_H
#define PLAYER_H
#include "counter.h"
#include <string>

using namespace std;


class Player
{
    public:

        Player (string);
        void printDetails ();
        void rollDie ();
        friend void Counter::onBoard (Player&, Counter&);
        bool getHasWon ();
        void setHasWon (bool hasWon);

        string getName () {return name;};
        unsigned short getNumberThrown () {return numberThrown;};

    private:
        string name;
        unsigned short rank, numberThrown, dieNumber, dieNumberBoard;
        bool hasWon;
};

#endif // PLAYER_H
