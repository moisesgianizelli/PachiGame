#include "player.h"
#include <iostream>


Player::Player(string playerNo) {
    cout << "\tEnter the name of the " << playerNo << " player: ";
    cin >> name;
    rank = 0;
}

void Player::rollDie() {
        dieNumber = rand () % 6 + 1;
        cout << "\n\t\tThe Number thrown was " << dieNumber;
}

bool Player::getHasWon () {
    return this->hasWon;
}

void Player::setHasWon (bool hasWon) {
    this->hasWon = hasWon;
}
