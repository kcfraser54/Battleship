// Kyle Fraser
// Battleship Driver

// Purpose: This program is designed so that two players may play battleship against one another and
// so that the player may also play battleship against the CPU.

// The interface also allows the user to see the leaderboards of the game, specifically, who has played
// and how many wins they have.

// names should not have a space in them.

// X coordinates denote rows
// Y coordinates denote columns

// The x and y coordinates used for ship placement denote the back of the ship.
// the orientation of the ship(1-4) denotes the direction it will be placed in.

// Attempt to sink all of your opponents ships.

#include <iostream>
#include <string>
#include <random>
#include "player.h"
#include "leaderBoard.h";
#include "cpu_Player.h"
using namespace std;

void welcome();
void goodbye();

void twoPlayerSetUp(player& p1, player& p2);
void onePlayerSetUp(player& p1, cpu_Player& p2);
void twoPlayerGameplay(player& p1, player& p2);
void onePlayerGameplay(player& p1, cpu_Player& p2);
void congratulations(string playerName);
int randomNumberGenerator(int num1, int num2);

leaderBoard l;
const int TOTAL_MOVES = 64;
const int MIN_ORIENTATION = 1;
const int MAX_ORIENTATION = 4;
const int MIN_PLACEMENT = 0;
const int MAX_PLACEMENT = 7;

const char YES = 'y';
int main() {


    int menuChoice;
    char enter;
    bool bye = false;
    welcome();
    cout << endl << endl;
    cout << "Enter the Game(y/n): ";
    cin >> enter;
    while(enter == YES) {
        cout << endl << endl;
        cout << endl << endl;
        cout << "1. 2 Player Game" << endl;
        cout << "2. Play vs Computer" << endl;
        cout << "3. View Leaderboards" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Enter choice: ";
        cin >> menuChoice;


        switch (menuChoice) {
            case 1: {
                player p1, p2;
                twoPlayerSetUp(p1, p2);
                if(p1.gridSet() && p2.gridSet()) {
                    twoPlayerGameplay(p1, p2);
                }
                break;
            }
            case 2: {
                player p1;
                cpu_Player c1;
                onePlayerSetUp(p1, c1);
                if(p1.gridSet() && c1.gridSet()) {
                    onePlayerGameplay(p1, c1);
                }
                break;
            }
            case 3: {
                cout << endl << endl;
                l.printLeaderboard();
                break;
            }
            case 4: {
                cout << endl << endl;
                goodbye();
                return 0;

            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }

        if(!bye) {
            cout << endl << endl;
            cout << "Back to the menu?(y/n): ";
            cin >> enter;
            if(enter != YES){
                goodbye();
            }
        }

    }

    return 0;
}

void welcome(){
    cout << endl << endl;
    cout << "Welcome to the game of Battleship!!!";
    cout << endl << endl;
}

void goodbye(){
    cout << "Thanks for playing!";
    cout << endl << endl;
}

void twoPlayerSetUp(player& p1, player& p2){

    string player1Name;
    string player2Name;

    int carrierPlacementResponse;
    int battleshipPlacementResponse;
    int cruiserPlacementResponse;
    int submarinePlacementResponse;
    int destroyerPlacementResponse;
    int xCoord;
    int yCoord;
    int shipOrientation;
    char play;

    cout << endl << endl;
    cout << "Player 1, enter your name: ";
    cin >> player1Name;
    cin.ignore();

    if(!l.playerExists(player1Name)){

        l.addPlayer(player1Name);

    }

    cout << endl << endl;
    cout << endl << endl;
    cout << "Player 2, enter your name: ";
    cin >> player2Name;

    if(!l.playerExists(player2Name)){

        l.addPlayer(player2Name);
    }

    cout << endl << endl;
    p1.setName(player1Name);
    p2.setName(player2Name);

    cout << endl << endl;
    cout << p1.getName() << ", Press y to begin the game: ";
    cin >> play;

    if(play == YES) {
        carrierPlacementResponse = -1;
        battleshipPlacementResponse = -1;
        cruiserPlacementResponse = -1;
        submarinePlacementResponse = -1;
        destroyerPlacementResponse = -1;
        cout << endl << endl;
        cout << p1.getName() << ", place your ships!";
        cout << endl << endl;
        while (carrierPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for carrier placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for carrier placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            carrierPlacementResponse = p1.placeC(xCoord, yCoord, shipOrientation);
        }

        while (battleshipPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for battleship placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for battleship placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            battleshipPlacementResponse = p1.placeB(xCoord, yCoord, shipOrientation);
        }

        while (cruiserPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for cruiser placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for cruiser placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            cruiserPlacementResponse = p1.placeCR(xCoord, yCoord, shipOrientation);
        }

        while (submarinePlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for submarine placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for submarine placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            submarinePlacementResponse = p1.placeS(xCoord, yCoord, shipOrientation);
        }

        while (destroyerPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for destroyer placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for destroyer placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            destroyerPlacementResponse = p1.placeD(xCoord, yCoord, shipOrientation);
        }

        carrierPlacementResponse = -1;
        battleshipPlacementResponse = -1;
        cruiserPlacementResponse = -1;
        submarinePlacementResponse = -1;
        destroyerPlacementResponse = -1;

        cout << endl << endl;
        cout << p2.getName() << ", place your ships!!!";
        cout << endl << endl;
        while (carrierPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for carrier placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for carrier placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            carrierPlacementResponse = p2.placeC(xCoord, yCoord, shipOrientation);
        }

        while (battleshipPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for battleship placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for battleship placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            battleshipPlacementResponse = p2.placeB(xCoord, yCoord, shipOrientation);
        }

        while (cruiserPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for cruiser placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for cruiser placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            cruiserPlacementResponse = p2.placeCR(xCoord, yCoord, shipOrientation);
        }

        while (submarinePlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for submarine placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for submarine placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            submarinePlacementResponse = p2.placeS(xCoord, yCoord, shipOrientation);
        }

        while (destroyerPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for destroyer placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for destroyer placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cin.ignore();
            cout << endl << endl;
            destroyerPlacementResponse = p2.placeD(xCoord, yCoord, shipOrientation);
        }

    }

}

void twoPlayerGameplay(player& p1, player& p2) {

    int attackX;
    int attackY;
    char result;
    char begin;
    bool gameOver = false;
        while (!gameOver) {
            cout << endl << endl;
            cout << p1.getName() << "'s, turn";
            cout << endl << endl;
            cout << p2.getName() << "'s grid" << endl;
            p1.printEnemyGrid();
            cout << endl;
            cout << p1.getName() << ", choose an x coordinate for attack(0-7): ";
            cin >> attackX;
            cout << endl << endl;
            cout << p1.getName() << ", choose a y coordinate for attack(0-7): ";
            cin >> attackY;
            cout << endl << endl;
            result = p2.beingAttacked(attackX, attackY);
            p1.updateEnemyGrid(attackX, attackY, result);
            if (p2.lost()) {
                l.updateLeaderboard(p1.getName());
                congratulations(p1.getName());
                gameOver = true;
            } else {
                cout << endl << endl;
                cout << p2.getName() << "'s turn";
                cout << endl << endl;
                cout << p1.getName() << "'s grid" << endl;
                p2.printEnemyGrid();
                cout << endl;
                cout << p2.getName() << ", choose an x coordinate for attack(0-7): ";
                cin >> attackX;
                cout << endl << endl;
                cout << p2.getName() << ", choose a y coordinate for attack(0-7): ";
                cin >> attackY;
                cout << endl << endl;
                result = p1.beingAttacked(attackX, attackY);
                p2.updateEnemyGrid(attackX, attackY, result);
                if (p1.lost()) {
                    l.updateLeaderboard(p2.getName());
                    congratulations(p2.getName());
                    gameOver = true;
                }

            }

        }


}


void onePlayerSetUp(player& p1, cpu_Player& c1){

    string player1Name;


    int carrierPlacementResponse;
    int battleshipPlacementResponse;
    int cruiserPlacementResponse;
    int submarinePlacementResponse;
    int destroyerPlacementResponse;
    int xCoord;
    int yCoord;
    int shipOrientation;
    char play;

    cout << endl << endl;
    cout << "Player 1, enter your name: ";
    cin >> player1Name;
    cin.ignore();

    if(!l.playerExists(player1Name)){

        l.addPlayer(player1Name);

    }

    if(!l.playerExists(c1.getName())){

        l.addPlayer(c1.getName());
    }

    cout << endl << endl;
    p1.setName(player1Name);

    cout << endl << endl;
    cout << p1.getName() << ", Press y to begin the game: ";
    cin >> play;

    if(play == YES) {
        carrierPlacementResponse = -1;
        battleshipPlacementResponse = -1;
        cruiserPlacementResponse = -1;
        submarinePlacementResponse = -1;
        destroyerPlacementResponse = -1;
        cout << endl << endl;
        cout << p1.getName() << ", place your ships!";
        cout << endl << endl;
        while (carrierPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for carrier placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for carrier placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            carrierPlacementResponse = p1.placeC(xCoord, yCoord, shipOrientation);
        }

        while (battleshipPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for battleship placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for battleship placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            battleshipPlacementResponse = p1.placeB(xCoord, yCoord, shipOrientation);
        }

        while (cruiserPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for cruiser placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for cruiser placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            cruiserPlacementResponse = p1.placeCR(xCoord, yCoord, shipOrientation);
        }

        while (submarinePlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for submarine placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for submarine placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            submarinePlacementResponse = p1.placeS(xCoord, yCoord, shipOrientation);
        }

        while (destroyerPlacementResponse != 1) {
            cout << endl << endl;
            cout << "Choose your x coordinate for destroyer placement(0-7): ";
            cin >> xCoord;
            cout << endl << endl;
            cout << "Choose your y coordinate for destroyer placement(0-7): ";
            cin >> yCoord;
            cout << endl << endl;
            cout << "1 = ship facing up" << endl;
            cout << "2 = ship facing right" << endl;
            cout << "3 = ship facing left" << endl;
            cout << "4 = ship facing down" << endl;
            cout << "Choose the orientation of your ship(1-4): ";
            cin >> shipOrientation;
            cout << endl << endl;
            destroyerPlacementResponse = p1.placeD(xCoord, yCoord, shipOrientation);
        }

        carrierPlacementResponse = -1;
        battleshipPlacementResponse = -1;
        cruiserPlacementResponse = -1;
        submarinePlacementResponse = -1;
        destroyerPlacementResponse = -1;

        cout << endl << endl;
        cout << c1.getName() << ", place your ships!!!";
        cout << endl << endl;
        while (carrierPlacementResponse != 1) {
            xCoord = randomNumberGenerator(MIN_PLACEMENT, MAX_PLACEMENT);
            yCoord = randomNumberGenerator(MIN_PLACEMENT, MAX_PLACEMENT);
            shipOrientation = randomNumberGenerator(MIN_ORIENTATION, MAX_ORIENTATION);
            carrierPlacementResponse = c1.placeC(xCoord, yCoord, shipOrientation);
        }

        while (battleshipPlacementResponse != 1) {
            xCoord = randomNumberGenerator(MIN_PLACEMENT, MAX_PLACEMENT);
            yCoord = randomNumberGenerator(MIN_PLACEMENT, MAX_PLACEMENT);
            shipOrientation = randomNumberGenerator(MIN_ORIENTATION, MAX_ORIENTATION);
            battleshipPlacementResponse = c1.placeB(xCoord, yCoord, shipOrientation);
        }

        while (cruiserPlacementResponse != 1) {
            xCoord = randomNumberGenerator(MIN_PLACEMENT, MAX_PLACEMENT);
            yCoord = randomNumberGenerator(MIN_PLACEMENT, MAX_PLACEMENT);
            shipOrientation = randomNumberGenerator(MIN_ORIENTATION, MAX_ORIENTATION);
            cruiserPlacementResponse = c1.placeCR(xCoord, yCoord, shipOrientation);
        }

        while (submarinePlacementResponse != 1) {
            xCoord = randomNumberGenerator(MIN_PLACEMENT, MAX_PLACEMENT);
            yCoord = randomNumberGenerator(MIN_PLACEMENT, MAX_PLACEMENT);
            shipOrientation = randomNumberGenerator(MIN_ORIENTATION, MAX_ORIENTATION);
            submarinePlacementResponse = c1.placeS(xCoord, yCoord, shipOrientation);
        }

        while (destroyerPlacementResponse != 1) {
            xCoord = randomNumberGenerator(MIN_PLACEMENT, MAX_PLACEMENT);
            yCoord = randomNumberGenerator(MIN_PLACEMENT, MAX_PLACEMENT);
            shipOrientation = randomNumberGenerator(MIN_ORIENTATION, MAX_ORIENTATION);
            destroyerPlacementResponse = c1.placeD(xCoord, yCoord, shipOrientation);
        }

    }

}

void onePlayerGameplay(player& p1, cpu_Player& c1){
    int betterGuess[TOTAL_MOVES];
    for(int i = 0; i < TOTAL_MOVES; i++){
        betterGuess[i] = -1;
    }
    int duplicateCount;
    bool guessInProgress = true;
    int moveCount = 0;
    int attackX;
    int attackY;
    char result;
    char begin;
    bool gameOver = false;
        while (!gameOver) {
            cout << endl << endl;
            cout << p1.getName() << "'s, turn";
            cout << endl << endl;
            cout << c1.getName() << "'s grid" << endl;
            p1.printEnemyGrid();
            cout << endl;
            cout << "Your grid" << endl;
            p1.printGrid();
            cout << endl;
            cout << p1.getName() << ", choose an x coordinate for attack(0-7): ";
            cin >> attackX;
            cout << endl << endl;
            cout << p1.getName() << ", choose a y coordinate for attack(0-7): ";
            cin >> attackY;
            cout << endl << endl;
            result = c1.beingAttacked(attackX, attackY);
            p1.updateEnemyGrid(attackX, attackY, result);
            if (c1.lost()) {
                l.updateLeaderboard(p1.getName());
                congratulations(p1.getName());
                gameOver = true;
            } else {

                cout << endl << endl;
                cout << c1.getName() << "'s turn";
                cout << endl << endl;
                while(guessInProgress) {
                    duplicateCount = 0;
                    attackX = c1.getPredictionX();
                    attackY = c1.getPredictionY();

                    for(int i = 0; i <= moveCount; i++){
                        if(((attackX * 10) + attackY) == betterGuess[i]){
                              duplicateCount++;
                        }
                    }
                    if(duplicateCount == 0) {
                        betterGuess[moveCount] = (attackX * 10) + attackY;
                        moveCount++;
                        guessInProgress = false;
                    }

                }
                guessInProgress = true;

                result = p1.beingAttacked(attackX, attackY);
                c1.updateEnemyGrid(attackX, attackY, result);
                if (p1.lost()) {
                    l.updateLeaderboard(c1.getName());
                    congratulations(c1.getName());
                    gameOver = true;
                }

            }

        }



}

void congratulations(string playerName){
    cout << endl << endl;
    cout << "Congratulations " << playerName << endl;
    cout << "You win battleship!!!";
    cout << endl << endl;
}

int randomNumberGenerator(int num1, int num2){
    int random;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(num1, num2);

    random = distr(gen);

    return random;
}

