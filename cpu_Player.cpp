// Kyle Fraser
// cpu_Player implementation file

#include "cpu_Player.h"
#include <random>

cpu_Player::~cpu_Player() = default;

char cpu_Player::beingAttacked(int x, int y) {

    if((x < 0 || x > 7) || (y < 0 || y > 7)){
        return MISS;
    }

    else {
        char whatHappened;
        if (enemyHit(x, y)) {
            whatHappened = HIT;
            char gotHit = whoGotHit(x, y);
            updateGrid(x, y);
            if (gotHit == CARRIER) {
                currentCarrierSize--;
                if (carrierLoss()) {

                    cout << endl << endl;
                    cout << cpuName << ", your carrier has been hit and sunk";
                    cout << endl << endl;
                } else {

                    cout << endl << endl;
                    cout << cpuName << ", one of your ships has been hit!";
                    cout << endl << endl;
                }


            } else if (gotHit == BATTLESHIP) {
                currentBattleshipSize--;
                if (battleshipLoss()) {

                    cout << endl << endl;
                    cout << cpuName << ", your battleship has been hit and sunk";
                    cout << endl << endl;

                } else {

                    cout << endl << endl;
                    cout << cpuName << ", one of your ships has been hit!";
                    cout << endl << endl;

                }


            } else if (gotHit == CRUISER) {
                currentCruiserSize--;
                if (cruiserLoss()) {


                    cout << endl << endl;
                    cout << cpuName << ", your cruiser has been hit and sunk";
                    cout << endl << endl;

                } else {

                    cout << endl << endl;
                    cout << cpuName << ", one of your ships has been hit!";
                    cout << endl << endl;

                }

            } else if (gotHit == SUBMARINE) {
                currentSubSize--;
                if (subLoss()) {

                    cout << endl << endl;
                    cout << cpuName << ", your submarine has been hit and sunk";
                    cout << endl << endl;
                } else {

                    cout << endl << endl;
                    cout << cpuName << ", one of your ships has been hit!";
                    cout << endl << endl;

                }


            } else if (gotHit == DESTROYER) {
                currentDestroyerSize--;
                if (destroyerLoss()) {

                    cout << endl << endl;
                    cout << cpuName << ", your destroyer has been hit and sunk";
                    cout << endl << endl;
                } else {

                    cout << endl << endl;
                    cout << cpuName << ", one of your ships has been hit";
                    cout << endl << endl;

                }

            }


        } else {

            whatHappened = MISS;
            cout << endl << endl;
            cout << cpuName << ", your opponent has missed!";
            cout << endl << endl;
        }

        return whatHappened;
    }
}

int cpu_Player::getPredictionX() {

    return randomGenerator();
}

int cpu_Player::getPredictionY() {

    return randomGenerator();
}

void cpu_Player::setName(string name) {

    //NOP
}

string cpu_Player::getName() {
    return cpuName;
}

void cpu_Player::printGrid() {

    cout << "- - - - - - - -" << endl;
    for(int i = 0; i < ROWS; i++){

        cout << "|";

        for(int j = 0; j < COLUMNS; j++){

            cout << grid[i][j] << " ";

        }
        cout << "|" << endl;
    }
    cout << " - - - - - - - -";
}

int cpu_Player::placeC(int startPointX, int startPointY, int orientation) {

    if((orientation != 1 && orientation != 2 && orientation != 3 && orientation != 4)
       || (startPointX < 0 && startPointX > 7) || (startPointY < 0 && startPointY > 7)){
        return -1;
    }

    else {

        if (mayPlace(startPointX, startPointY, orientation, CARRIER)) {

            if (orientation == 1) {

                for (int i = startPointX; i > startPointX - CARRIER_SIZE; i--) {

                    grid[i][startPointY] = CARRIER;

                }


            }
            else if (orientation == 2) {

                for (int i = startPointY; i < startPointY + CARRIER_SIZE; i++) {

                    grid[startPointX][i] = CARRIER;
                }

            }
            else if (orientation == 3) {

                for (int i = startPointY; i > startPointY - CARRIER_SIZE; i--) {

                    grid[startPointX][i] = CARRIER;
                }

            }
            else{

                for (int i = startPointX; i < startPointX + CARRIER_SIZE; i++) {

                    grid[i][startPointY] = CARRIER;
                }
            }

            CPlaced = true;
            cout << endl << endl;
            cout << "Carrier successfully placed";
            cout << endl << endl;
            return 1;
        }
        else {
            return -1;
        }
    }

}

int cpu_Player::placeB(int startPointX, int startPointY, int orientation) {
    if((orientation != 1 && orientation != 2 && orientation != 3 && orientation != 4)
       || (startPointX < 0 && startPointX > 7) || (startPointY < 0 && startPointY > 7)){
        return -1;
    }

    else {

        if (mayPlace(startPointX, startPointY, orientation, BATTLESHIP)) {

            if (orientation == 1) {

                for (int i = startPointX; i > startPointX - BATTLESHIP_SIZE; i--) {

                    grid[i][startPointY] = BATTLESHIP;

                }


            }
            else if (orientation == 2) {

                for (int i = startPointY; i < startPointY + BATTLESHIP_SIZE; i++) {

                    grid[startPointX][i] = BATTLESHIP;
                }

            }
            else if (orientation == 3) {

                for (int i = startPointY; i > startPointY - BATTLESHIP_SIZE; i--) {

                    grid[startPointX][i] = BATTLESHIP;
                }

            }
            else{

                for (int i = startPointX; i < startPointX + BATTLESHIP_SIZE; i++) {

                    grid[i][startPointY] = BATTLESHIP;
                }
            }

            BPlaced = true;
            cout << endl << endl;
            cout << "Battleship successfully placed";
            cout << endl << endl;
            return 1;
        }
        else {
            return -1;
        }
    }

}

int cpu_Player::placeCR(int startPointX, int startPointY, int orientation) {
    if((orientation != 1 && orientation != 2 && orientation != 3 && orientation != 4)
       || (startPointX < 0 && startPointX > 7) || (startPointY < 0 && startPointY > 7)){
        return -1;
    }

    else {

        if (mayPlace(startPointX, startPointY, orientation, CRUISER)) {

            if (orientation == 1) {

                for (int i = startPointX; i > startPointX - CRUISER_SIZE; i--) {

                    grid[i][startPointY] = CRUISER;

                }


            }
            else if (orientation == 2) {

                for (int i = startPointY; i < startPointY + CRUISER_SIZE; i++) {

                    grid[startPointX][i] = CRUISER;
                }

            }
            else if (orientation == 3) {

                for (int i = startPointY; i > startPointY - CRUISER_SIZE; i--) {

                    grid[startPointX][i] = CRUISER;
                }

            }
            else{

                for (int i = startPointX; i < startPointX + CRUISER_SIZE; i++) {

                    grid[i][startPointY] = CRUISER;
                }
            }

            RPlaced = true;
            cout << endl << endl;
            cout << "Cruiser successfully placed";
            cout << endl << endl;
            return 1;
        }
        else {
            return -1;
        }
    }

}

int cpu_Player::placeS(int startPointX, int startPointY, int orientation) {

    if((orientation != 1 && orientation != 2 && orientation != 3 && orientation != 4)
       || (startPointX < 0 && startPointX > 7) || (startPointY < 0 && startPointY > 7)){
        return -1;
    }

    else {
        if (mayPlace(startPointX, startPointY, orientation, SUBMARINE)) {

            if (orientation == 1) {

                for (int i = startPointX; i > startPointX - SUBMARINE_SIZE; i--) {

                    grid[i][startPointY] = SUBMARINE;

                }


            }
            else if (orientation == 2) {

                for (int i = startPointY; i < startPointY + SUBMARINE_SIZE; i++) {

                    grid[startPointX][i] = SUBMARINE;
                }

            }
            else if (orientation == 3) {

                for (int i = startPointY; i > startPointY - SUBMARINE_SIZE; i--) {

                    grid[startPointX][i] = SUBMARINE;
                }

            }
            else{

                for (int i = startPointX; i < startPointX + SUBMARINE_SIZE; i++) {

                    grid[i][startPointY] = SUBMARINE;
                }
            }

            SPlaced = true;
            cout << endl << endl;
            cout << "Submarine successfully placed";
            cout << endl << endl;
            return 1;
        }
        else {
            return -1;
        }
    }

}

int cpu_Player::placeD(int startPointX, int startPointY, int orientation) {

    if((orientation != 1 && orientation != 2 && orientation != 3 && orientation != 4)
       || (startPointX < 0 && startPointX > 7) || (startPointY < 0 && startPointY > 7)){
        return -1;
    }

    else {

        if (mayPlace(startPointX, startPointY, orientation, DESTROYER)) {

            if (orientation == 1) {

                for (int i = startPointX; i > startPointX - DESTROYER_SIZE; i--) {

                    grid[i][startPointY] = DESTROYER;

                }


            }
            else if (orientation == 2) {

                for (int i = startPointY; i < startPointY + DESTROYER_SIZE; i++) {

                    grid[startPointX][i] = DESTROYER;
                }

            }
            else if (orientation == 3) {

                for (int i = startPointY; i > startPointY - DESTROYER_SIZE; i--) {

                    grid[startPointX][i] = DESTROYER;
                }

            }
            else{

                for (int i = startPointX; i < startPointX + DESTROYER_SIZE; i++) {

                    grid[i][startPointY] = DESTROYER;
                }
            }

            DPlaced = true;
            cout << endl << endl;
            cout << "Destroyer successfully placed";
            cout << endl << endl;
            return 1;
        }
        else {
            return -1;
        }
    }



}

int cpu_Player::randomGenerator() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(MIN_ATTACK, MAX_ATTACK);

    random = distr(gen);

    return random;

}