// Kyle Fraser
// cpu_player specification file

// The cpu_player class inherits the functionality of the player class and
// allows a user to play battleship against the cpu.

#ifndef BATTLESHIP1_CPU_PLAYER_H
#define BATTLESHIP1_CPU_PLAYER_H
#include "player.h";

class cpu_Player : public player {


    cpu_Player(const cpu_Player& obj);
    cpu_Player& operator=(const cpu_Player& rhs);
    int randomGenerator();
    const string cpuName = "VAL";
    const int MIN_ATTACK = 0;
    const int MAX_ATTACK = 7;
    int random;


public:

    cpu_Player() : player(){}
    ~cpu_Player();


    void setName(string name) override;
    void printGrid() override;
    int placeC(int startPointX, int startPointY, int orientation) override;
    int placeB(int startPointX, int startPointY, int orientation) override;
    int placeCR(int startPointX, int startPointY, int orientation) override;
    int placeD(int startPointX, int startPointY, int orientation) override;
    int placeS(int startPointX, int startPointY, int orientation) override;
    int getPredictionX();
    int getPredictionY();
    string getName() override;
    char beingAttacked(int x, int y) override;
};


#endif //BATTLESHIP1_CPU_PLAYER_H
