// Kyle Fraser
// player specification file

// The player class provides the functionality of a battleship player


#include <iostream>
#include <string>
using namespace std;

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H


class player {

    player(const player& obj);
    player& operator=(const player& rhs);

protected:

    bool mayPlace(int startPointX, int startPointY, int orientation, char ship);
    bool enemyHit(int x, int y);
    char whoGotHit(int x, int y);

    const int CARRIER_SIZE = 5;
    const int BATTLESHIP_SIZE = 4;
    const int CRUISER_SIZE = 3;
    const int SUBMARINE_SIZE = 3;
    const int DESTROYER_SIZE = 2;
    const int ROWS = 8;
    const int COLUMNS = 8;

    const char OPEN_OCEAN = '~';
    const char CARRIER = 'C';
    const char BATTLESHIP = 'B';
    const char CRUISER = 'R';
    const char SUBMARINE = 'S';
    const char DESTROYER = 'D';
    const char BLOWN_UP = 'X';

    const char HIT = 'H';
    const char MISS = 'M';

    bool CPlaced;
    bool BPlaced;
    bool RPlaced;
    bool SPlaced;
    bool DPlaced;

    bool carrierLost;
    bool battleshipLost;
    bool cruiserLost;
    bool submarineLost;
    bool destroyerLost;

    int currentCarrierSize;
    int currentBattleshipSize;
    int currentCruiserSize;
    int currentSubSize;
    int currentDestroyerSize;
    int shipLoss;

    char knownEnemyStatus[8][8];
    char grid[8][8];

    string name;
    bool carrierLoss();
    bool battleshipLoss();
    bool cruiserLoss();
    bool subLoss();
    bool destroyerLoss();

public:
    player();
    virtual ~player();
    bool gridSet();
    bool lost();

    virtual void printGrid();
    void printEnemyGrid();
    void updateGrid(int x, int y);
    void updateEnemyGrid(int x, int y, char result);
    virtual void setName(string Name1);
    virtual string getName();

    virtual int placeC(int startPointX, int startPointY, int orientation);
    virtual int placeB(int startPointX, int startPointY, int orientation);
    virtual int placeCR(int startPointX, int startPointY, int orientation);
    virtual int placeS(int startPointX, int startPointY, int orientation);
    virtual int placeD(int startPointX, int startPointY, int orientation);
    virtual char beingAttacked(int x, int y);
    void reset();


};


#endif //BATTLESHIP_PLAYER_H
