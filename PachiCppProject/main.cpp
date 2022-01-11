/* Written by @Moises Gianizelli
Start Date: 04/12/2021
Last Update: 19/12/2021

* Pachi game is based on the classic Indian game Pachisi.
* The challenge is to develop this inspiration as our first project.
* The game consists of two players having two counters and they must move around the board until they reach the last space.
* The rules of the game are: cage, safe way to win and punishment for reached counter. */

#include <iostream>
#include "player.h"
#include <ctime>
#include "counter.h"
#include <conio.h>

using namespace std;

int main()
{
    string playAgain;
    do {
        //set players
      Player player1("Orange"), player2 ("Blue");
        // set counters
      Counter counter1 ("Orange", 1, 35, 40, false);
      Counter counter2 ("Blue", 21, 15, 20, true);
      bool gameOver = false;

      //random number
      srand(time(NULL));

        do {
          cout << "\n\tIt's " << player1.getName() << "'s turn. Press enter to roll the die";
          // brake
          getch ();
          player1.rollDie();
          counter1.onBoard(player1, counter2);

          if (!player1.getHasWon()) {
              cout << "\n\tIt's " << player2.getName() << "'s turn. Press enter to roll the die";
              getch ();
              player2.rollDie();
              counter2.onBoard(player2, counter1);
          }
      } while(!player1.getHasWon() && !player2.getHasWon());

      cout << "\n\tDo you want to play again? (y/n)\n";
      cin >> playAgain;

  } while (playAgain != "n");
    cout << "\n\tBye\n";


    return 0;
}
