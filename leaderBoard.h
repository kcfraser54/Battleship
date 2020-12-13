// Kyle Fraser
// leaderBoard specification file

// The leaderBoard class provides the functionality of the leaderboard. This class
// organizes player names in a file in descending order according to the number of wins
// a player has.

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef BATTLESHIP1_LEADERBOARD_H
#define BATTLESHIP1_LEADERBOARD_H


class leaderBoard {


    leaderBoard(const leaderBoard &obj);
    leaderBoard& operator=(const leaderBoard &rhs);


protected:

    ofstream LBFile;
    struct playerInfo{
        string playerName;
        int wins;
    };

    playerInfo* leaderBoardArray;
    playerInfo* temp;
    int numberOfEntries;
    string file;

    void sortLeaderBoard();
    void setPlayerInfoValues();
    void clearArray();
    int findNumberOfEntries();
    void resizeLeaderBoard();


public:

    leaderBoard();
    ~leaderBoard();
    void addPlayer(string player);
    void updateLeaderboard(string player);
    void printLeaderboard();
    bool playerExists(string player);

};


#endif //BATTLESHIP1_LEADERBOARD_H
