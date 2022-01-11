#include "counter.h"
#include "player.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
    Counter::Counter(string color, unsigned short initialPosition,
    unsigned short safePathThreshold, unsigned short endOfPath, bool shouldStartOver){
    color = this->color;

    // Counters position around the board
    this->initialPosition = initialPosition;
    this->position = initialPosition;
    this->safePathThreshold = safePathThreshold;
    this->endOfPath = endOfPath;
    this->inSafePath = false;
    this->shouldStartOver = shouldStartOver;
    this->startedOver = false;

    intheCage = true;
}

void Counter::onBoard(Player& currentPlayer, Counter& opponent) {

    //final game
    if (this->position + currentPlayer.dieNumber == this->endOfPath) {
        cout <<"\n\t" << currentPlayer.name << "\t********Has won the game!!*******";
        cout <<"\n\t" << currentPlayer.name << "\tHas increased rank +1";
        this->position += currentPlayer.dieNumber;
        currentPlayer.setHasWon(true);
        return;
    }

    if (this->inSafePath && this->position + currentPlayer.dieNumber == this->endOfPath) {
        cout <<"\n\t" << currentPlayer.name << "\t********Has won the game!!*******";
        cout <<"\n\t" << currentPlayer.name << "\tHas increased rank +1";
        this->position += currentPlayer.dieNumber;
        currentPlayer.setHasWon(true);
        return;
    }

    if (this->inSafePath) {
      return;
    }

    cout << "\n\t" << "Name: " << currentPlayer.name
    << "\n\tPosition: " << this->position;
    this->intheCage;


    //start game
    if (intheCage && currentPlayer.dieNumber == 6) {
        this->intheCage = false;
        cout << "\n\t" << currentPlayer.name << "\n\t********Has left the cage!!*******";

        cout << "\n\t\tRoll the die again";

        getch ();

        currentPlayer.rollDie();

    } else if (intheCage) {
        cout << "\n\t\t" << currentPlayer.name << " must roll a 6 to leave cage " << "\n";
        return;
    }

    //mid game
    if (this->shouldStartOver && (this->position + currentPlayer.dieNumber > 40)) {
        this->position = (this->position + currentPlayer.dieNumber) - 40;
        this->startedOver = true;
    } else {
        this->position += currentPlayer.dieNumber;
    }

    if (!this->shouldStartOver && this->position >= this->safePathThreshold) {
        this->inSafePath = true;
    } else if (this->shouldStartOver && this->startedOver && this->position >= this->safePathThreshold) {
        this->inSafePath = true;
    }


    //When counters are at the same spot
    if (this->position == opponent.position) {
        opponent.position = opponent.initialPosition;
        opponent.intheCage = true;
        cout << "\n\tOh no you have been hit :(" << " \n\t*********back to the cage!*********";
    }

    cout << "\n\t\t" << currentPlayer.name << " is at space number " << this->position << "\n";
}
