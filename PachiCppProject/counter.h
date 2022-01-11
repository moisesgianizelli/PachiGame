#ifndef COUNTER_H
#define COUNTER_H
#include <string>

using namespace std;

class Player;

class Counter {


    public:
        Counter(string, unsigned short, unsigned short, unsigned short, bool);
        void printDetails();
        // friends
        void onBoard(Player& , Counter& );
        int getPosition () {return position;};

    private:
        //unsigned short position;
        string color;
        unsigned short initialPosition, position, dieNumber, name, dieNumberBoard,
        safePathThreshold, endOfPath, inSafePath, shouldStartOver, startedOver;
        bool intheCage;
};

#endif // COUNTER_H
