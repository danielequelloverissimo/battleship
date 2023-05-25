/*
Copyright (c) 2023 danieleQuelloVero

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "BattleShip"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

// Constants
const char EMPTY_CHARACTER = '.';
const int MAX_ROWS = 9;
const int MAX_COLUMNS = 9;
const char WATER = 'W';
const int MAX_NUM_ATTEMPTS = 5;
const char SHIP = 'S';
const int WAIT_TIME = 2;

class BattleShipGame {
private:
    char map[MAX_ROWS][MAX_COLUMNS];
    int shipPosX;
    int shipPosY;
    int userPosX;
    int userPosY;
    int numAttempts;
    bool hit;

public:
    BattleShipGame() {
        srand(time(NULL));
        hit = false;
        numAttempts = 0;
        createMap();
        printMap();
        shipPosY = generateRandomNumber(MAX_ROWS);
        shipPosX = generateRandomNumber(MAX_COLUMNS);
        hideShip(shipPosX, shipPosY);
    }

    void createMap() {
        for (int row = 0; row < MAX_ROWS; row++) {
            for (int col = 0; col < MAX_COLUMNS; col++) {
                map[row][col] = EMPTY_CHARACTER;
            }
        }
    }

    void printMap() {
        for (int row = 0; row < MAX_ROWS; row++) {
            for (int col = 0; col < MAX_COLUMNS; col++) {
                cout << "\t" << map[row][col];
            }
            cout << endl;
        }
    }

    int generateRandomNumber(const int MAX_SIZE) {
        int randomNum = 0 + (rand() % MAX_SIZE);
        return randomNum;
    }

    void hideShip(int shipPosX, int shipPosY) {
        map[shipPosY][shipPosX] = SHIP;
    }

    void playGame() {
        while (!hit && numAttempts < MAX_NUM_ATTEMPTS) {
            cout << "Enter the X and Y values: " << endl;
            cin >> userPosY;
            cin >> userPosX;

            if (map[userPosY][userPosX] == SHIP) {
                hit = true;
                cout << "HIT!" << endl;
            } else {
                map[userPosY][userPosX] = WATER;
                numAttempts++;
                cout << "MISS! ATTEMPT NUMBER " << numAttempts << "\n\n" << endl;
            }
        }

        if (!hit) {
            cout << "MISS! OUT OF ATTEMPTS!" << endl;
        } else {
            cout << "You hit the ship in " << numAttempts << " attempts. Well done!" << endl;
        }

        sleep(WAIT_TIME);
        system("clear"); // change with "cls" if you are using Windows :)
        cout << "Here's the complete map: " << endl;
        printMap();
    }
};

int main() {
    BattleShipGame game;
    game.playGame();

    return 0;
}
