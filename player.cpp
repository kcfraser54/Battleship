// Kyle Fraser
// Battleship implementation file

#include <iostream>
#include <string>
using namespace std;
#include "player.h"


player::player(){

    name = "";

    CPlaced = false;
    BPlaced = false;
    RPlaced = false;
    SPlaced = false;
    DPlaced = false;

    carrierLost = false;
    battleshipLost = false;
    cruiserLost = false;
    submarineLost = false;
    destroyerLost = false;

    shipLoss = 0;

    currentCarrierSize = 5;
    currentBattleshipSize = 4;
    currentCruiserSize = 3;
    currentSubSize = 3;
    currentDestroyerSize = 2;


    for(int i = 0; i < ROWS; i++){

        for(int j = 0; j < COLUMNS; j++){

            grid[i][j] = OPEN_OCEAN;

        }
    }


    for(int i = 0; i < ROWS; i++){

        for(int j = 0; j < COLUMNS; j++){
            knownEnemyStatus[i][j] = OPEN_OCEAN;
        }
    }


}

player::~player() = default;

bool player::carrierLoss(){

    if(carrierLost){

        return true;
    }
    else {
        if (currentCarrierSize == 0) {
            shipLoss++;
            carrierLost = true;
            return true;
        }
        else {
            return false;
        }
    }

}

bool player::battleshipLoss(){

    if(battleshipLost){

        return true;
    }
    else {
        if (currentBattleshipSize == 0) {
            battleshipLost = true;
            shipLoss++;
            return true;
        }
        else {
            return false;
        }
    }
}

bool player::cruiserLoss(){

    if(cruiserLost){

        return true;
    }
    else {
        if (currentCruiserSize == 0) {
            cruiserLost = true;
            shipLoss++;
            return true;
        }
        else {
            return false;
        }
    }

}

bool player::subLoss(){

    if(submarineLost){

        return true;
    }
    else {
        if (currentSubSize == 0) {
            submarineLost = true;
            shipLoss++;
            return true;
        }
        else {
            return false;
        }
    }

}

bool player::destroyerLoss(){

    if(destroyerLost){

        return true;
    }
    else {
        if (currentDestroyerSize == 0) {
            destroyerLost = true;
            shipLoss++;
            return true;
        }
        else {
            return false;
        }
    }

}

bool player::gridSet(){

    return CPlaced == true && BPlaced == true && RPlaced == true
           && SPlaced == true && DPlaced == true;

}

bool player::lost(){

    return shipLoss == 5;
}

void player::printGrid(){

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

void player::printEnemyGrid(){

    cout << " - - - - - - - -" << endl;
    for(int i = 0; i < ROWS; i++){

        cout << "|";

        for(int j = 0; j < COLUMNS; j++){

            cout << knownEnemyStatus[i][j] << " ";

        }
        cout << "|" << endl;
    }

    cout << " - - - - - - - -";

}

void player::updateGrid(int x, int y){
    grid[x][y] = BLOWN_UP;
}

void player::updateEnemyGrid(int x, int y, char result){

    if(result == HIT){

        knownEnemyStatus[x][y] = HIT;

    }

    else if(result != HIT && knownEnemyStatus[x][y] != HIT){

        knownEnemyStatus[x][y] = MISS;

    }

}

int player::placeC(int startPointX, int startPointY, int orientation){

    if((orientation != 1 && orientation != 2 && orientation != 3 && orientation != 4)
       || (startPointX < 0 && startPointX > 7) || (startPointY < 0 && startPointY > 7)){

        cout << endl << endl;
        cout << "Error: Orientation of ship must be between 1-4 and coordinate values must be"  << endl;
        cout << "between 0-7";
        cout << endl << endl;
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
            cout << endl << endl;
            cout << "Error: Carrier could not be placed. Place you carrier in a valid position";
            return -1;
        }
    }
}

int player::placeB(int startPointX, int startPointY, int orientation){

    if((orientation != 1 && orientation != 2 && orientation != 3 && orientation != 4)
               || (startPointX < 0 && startPointX > 7) || (startPointY < 0 && startPointY > 7)){

        cout << endl << endl;
        cout << "Error: Orientation of ship must be between 1-4 and coordinate values must be" << endl;
        cout << "between 0-7";
        cout << endl << endl;
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
            cout << endl << endl;
            cout << "Error: Battleship could not be placed. Place your battleship in a valid position";
            cout << endl << endl;
            return -1;
        }
    }


}
int player::placeCR(int startPointX, int startPointY, int orientation){

    if((orientation != 1 && orientation != 2 && orientation != 3 && orientation != 4)
       || (startPointX < 0 && startPointX > 7) || (startPointY < 0 && startPointY > 7)){

        cout << endl << endl;
        cout << "Error: Orientation of ship must be between 1-4 and coordinate values must be" << endl;
        cout << "Between 0-7";
        cout << endl << endl;
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
            cout << endl << endl;
            cout << "Error: Cruiser could not be placed. Place your cruiser in a valid position";
            cout << endl << endl;
            return -1;
        }
    }

}
int player::placeS(int startPointX, int startPointY, int orientation){

    if((orientation != 1 && orientation != 2 && orientation != 3 && orientation != 4)
       || (startPointX < 0 && startPointX > 7) || (startPointY < 0 && startPointY > 7)){

        cout << endl << endl;
        cout << "Error: Orientation of ship must be between 1-4 and coordinate values must be" << endl;
        cout << "between 0-7";
        cout << endl << endl;
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
            cout << endl << endl;
            cout << "Error: Submarine could not be placed. Place you submarine in a valid position";
            cout << endl << endl;
            return -1;
        }
    }
}
int player::placeD(int startPointX, int startPointY, int orientation){

    if((orientation != 1 && orientation != 2 && orientation != 3 && orientation != 4)
       || (startPointX < 0 && startPointX > 7) || (startPointY < 0 && startPointY > 7)){

        cout << endl << endl;
        cout << "Error: Orientation of ship must be between 1-4 and coordinate values must be" << endl;
        cout << "Between 0-7";
        cout << endl << endl;
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
            cout << endl << endl;
            cout << "Error: Destroyer could not be placed. Place your destroyer in a valid position";
            cout << endl << endl;
            return -1;
        }
    }

}

char player::beingAttacked(int x, int y){

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
                    cout << name << ", your carrier has been hit and sunk";
                    cout << endl << endl;
                } else {

                    cout << endl << endl;
                    cout << name << ", one of your ships has been hit!";
                    cout << endl << endl;
                }


            } else if (gotHit == BATTLESHIP) {
                currentBattleshipSize--;
                if (battleshipLoss()) {

                    cout << endl << endl;
                    cout << name << ", your battleship has been hit and sunk";
                    cout << endl << endl;

                } else {

                    cout << endl << endl;
                    cout << name << ", one of your ships has been hit!";
                    cout << endl << endl;

                }


            } else if (gotHit == CRUISER) {
                currentCruiserSize--;
                if (cruiserLoss()) {


                    cout << endl << endl;
                    cout << name << ", your cruiser has been hit and sunk";
                    cout << endl << endl;

                } else {

                    cout << endl << endl;
                    cout << name << ", one of your ships has been hit!";
                    cout << endl << endl;

                }

            } else if (gotHit == SUBMARINE) {
                currentSubSize--;
                if (subLoss()) {

                    cout << endl << endl;
                    cout << name << ", your submarine has been hit and sunk";
                    cout << endl << endl;
                } else {

                    cout << endl << endl;
                    cout << name << ", one of your ships has been hit!";
                    cout << endl << endl;

                }


            } else if (gotHit == DESTROYER) {
                currentDestroyerSize--;
                if (destroyerLoss()) {

                    cout << endl << endl;
                    cout << name << ", your destroyer has been hit and sunk";
                    cout << endl << endl;
                } else {

                    cout << endl << endl;
                    cout << name << ", one of your ships has been hit";
                    cout << endl << endl;

                }

            }


        } else {

            whatHappened = MISS;
            cout << endl << endl;
            cout << name << ", your opponent has missed!";
            cout << endl << endl;
        }

        return whatHappened;
    }
}

bool player::mayPlace(int startPointX, int startPointY, int orientation, char ship){

    bool placeShip = true;

    if(ship == CARRIER){

        if(orientation == 1){

            for(int i = startPointX; i > -1 && i > startPointX - CARRIER_SIZE; i--){

                if(grid[i][startPointY] != OPEN_OCEAN || startPointX - CARRIER_SIZE < 0){

                    placeShip = false;
                }


            }


        }

        else if(orientation == 2){

            for(int k = startPointY; k < startPointY + CARRIER_SIZE && k < ROWS; k++){

                if(grid[startPointX][k] != OPEN_OCEAN || startPointY + CARRIER_SIZE > 7){
                    placeShip = false;
                }


            }

        }

        else if(orientation == 3){

            for(int k = startPointY; k > -1 && k > startPointY - CARRIER_SIZE; k--){

                if(grid[startPointX][k] != OPEN_OCEAN || startPointY - CARRIER_SIZE < 0){

                    placeShip = false;
                }

            }

        }

        else{

            for(int i = startPointX; i < ROWS && i < startPointX + CARRIER_SIZE; i++){

                if(grid[i][startPointY] != OPEN_OCEAN || startPointX + CARRIER_SIZE > 7){

                    placeShip = false;

                }

            }


        }

    }

    else if(ship == BATTLESHIP){

        if(orientation == 1){

            for(int i = startPointX; i > -1 && i > startPointX - BATTLESHIP_SIZE; i--){

                if(grid[i][startPointY] != OPEN_OCEAN || startPointX - BATTLESHIP_SIZE < 0){

                    placeShip = false;
                }


            }


        }

        else if(orientation == 2){

            for(int k = startPointY; k < startPointY + BATTLESHIP_SIZE && k < COLUMNS; k++){

                if(grid[startPointX][k] != OPEN_OCEAN || startPointY + BATTLESHIP_SIZE > 7){
                    placeShip = false;
                }

            }
        }

        else if(orientation == 3){

            for(int k = startPointY; k > -1 && k > startPointY - BATTLESHIP_SIZE; k--){

                if(grid[startPointX][k] != OPEN_OCEAN || startPointY - BATTLESHIP_SIZE < 0){

                    placeShip = false;
                }

            }

        }

        else{

            for(int i = startPointX; i < ROWS && i < startPointX + BATTLESHIP_SIZE; i++){

                if(grid[i][startPointY] != OPEN_OCEAN || startPointX + BATTLESHIP_SIZE > 7){

                    placeShip = false;

                }

            }

        }


    }

    else if(ship == CRUISER){

        if(orientation == 1){

            for(int i = startPointX; i > -1 && i > startPointY - CRUISER_SIZE ; i--){

                if(grid[i][startPointY] != OPEN_OCEAN || startPointX - CRUISER_SIZE < 0){

                    placeShip = false;
                }


            }

        }

        else if(orientation == 2){

            for(int k = startPointY; k < startPointY + CRUISER_SIZE && k < COLUMNS; k++){

                if(grid[startPointX][k] != OPEN_OCEAN || startPointY + CRUISER_SIZE > 7){
                    placeShip = false;
                }

            }



        }

        else if(orientation == 3){

            for(int k = startPointY; k > -1 && k > startPointY - CRUISER_SIZE; k--){

                if(grid[startPointX][k] != OPEN_OCEAN || startPointY - CRUISER_SIZE < 0){

                    placeShip = false;
                }

            }

        }

        else{

            for(int i = startPointX; i < ROWS && i < startPointX + CRUISER_SIZE; i++){

                if(grid[i][startPointY] != OPEN_OCEAN || startPointX + CRUISER_SIZE > 7){

                    placeShip = false;

                }

            }


        }

    }

    else if(ship == SUBMARINE){

        if(orientation == 1){

            for(int i = startPointX; i > -1 && i > startPointX - SUBMARINE_SIZE; i--){

                if(grid[i][startPointY] != OPEN_OCEAN || startPointX - SUBMARINE_SIZE < 0){

                    placeShip = false;
                }


            }

        }

        else if(orientation == 2){

            for(int k = startPointY; k < startPointY + SUBMARINE_SIZE && k < COLUMNS; k++){

                if(grid[startPointX][k] != OPEN_OCEAN || startPointY + SUBMARINE_SIZE > 7){
                    placeShip = false;
                }

            }

        }

        else if(orientation == 3){

            for(int k = startPointY; k > -1 && k > startPointY - SUBMARINE_SIZE; k--){

                if(grid[startPointX][k] != OPEN_OCEAN || startPointY - SUBMARINE_SIZE < 0){

                    placeShip = false;
                }

            }

        }

        else{
            for(int i = startPointX; i < ROWS && i < startPointX + SUBMARINE_SIZE; i++){

                if(grid[i][startPointY] != OPEN_OCEAN || startPointX + SUBMARINE_SIZE > 7){

                    placeShip = false;

                }

            }

        }

    }

    else if(ship == DESTROYER){

        if(orientation == 1){
            for(int i = startPointX; i > -1 && i > startPointX - DESTROYER_SIZE; i--){

                if(grid[i][startPointY] != OPEN_OCEAN || startPointX - DESTROYER_SIZE < 0){

                    placeShip = false;
                }


            }

        }

        else if(orientation == 2){

            for(int k = startPointY; k < startPointY + DESTROYER_SIZE && k < COLUMNS; k++){

                if(grid[startPointX][k] != OPEN_OCEAN || startPointY + DESTROYER_SIZE > 7){
                    placeShip = false;
                }

            }

        }

        else if(orientation == 3){

            for(int k = startPointY; k > -1 && k > startPointY - DESTROYER_SIZE; k--){

                if(grid[startPointX][k] != OPEN_OCEAN || startPointY - DESTROYER_SIZE < 0){

                    placeShip = false;
                }

            }


        }

        else{

            for(int i = startPointX; i < ROWS && i < startPointX + DESTROYER_SIZE; i++){

                if(grid[i][startPointY] != OPEN_OCEAN || startPointX + DESTROYER_SIZE > 7){

                    placeShip = false;

                }

            }

        }

    }
    else{

        cout << endl << endl;
        cout << "Error: The correct ship was not entered, please enter a valid ship";
        cout << endl << endl;
        placeShip = false;
    }


    return placeShip;

}


bool player::enemyHit(int x, int y){

    if(grid[x][y] != OPEN_OCEAN && grid[x][y] != BLOWN_UP){

        return true;
    }
    else{
        return false;
    }

}


char player::whoGotHit(int x, int y){

    if(grid[x][y] == CARRIER){

        return CARRIER;
    }

    else if(grid[x][y] == BATTLESHIP){
        return BATTLESHIP;
    }

    else if(grid[x][y] == CRUISER){

        return CRUISER;
    }

    else if(grid[x][y] == SUBMARINE){

        return SUBMARINE;
    }

    else if(grid[x][y] == DESTROYER){

        return DESTROYER;
    }
}


void player::reset(){

    CPlaced = false;
    BPlaced = false;
    RPlaced = false;
    SPlaced = false;
    DPlaced = false;

    carrierLost = false;
    battleshipLost = false;
    cruiserLost = false;
    submarineLost = false;
    destroyerLost = false;


    shipLoss = 0;

    currentCarrierSize = 5;
    currentBattleshipSize = 4;
    currentCruiserSize = 3;
    currentSubSize = 3;
    currentDestroyerSize = 2;

    for(int i = 0; i < ROWS; i++){

        for(int j = 0; j < COLUMNS; j++){

            grid[i][j] = OPEN_OCEAN;

        }
    }

    for(int i = 0; i < ROWS; i++){

        for(int j = 0; j < COLUMNS; j++){
            knownEnemyStatus[i][j] = OPEN_OCEAN;
        }
    }

}

string player::getName(){

    return name;

}

void player::setName(string playerName){

    name = playerName;
}



