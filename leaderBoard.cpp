// Kyle Fraser
// leaderBoard implementation file

#include <string>
#include <fstream>
#include <iostream>
#include "leaderBoard.h"
#include <cctype>
using namespace std;

leaderBoard::leaderBoard(){

    file = "C:\\Users\\kcfra\\Desktop\\C++ stuff\\battleship1\\leaderboard.txt";
    numberOfEntries = findNumberOfEntries();
    leaderBoardArray = new playerInfo[numberOfEntries];
    for(int i = 0; i < numberOfEntries; i++){

    leaderBoardArray[i].playerName = "";
    leaderBoardArray[i].wins = 0;

    }

}

leaderBoard::~leaderBoard(){

  delete [] leaderBoardArray;

}

//leaderBoard::leaderBoard(const leaderBoard &obj){

    // NOP

//}

//leaderBoard& leaderBoard::operator=(const leaderBoard &rhs){

    // NOP
//}


void leaderBoard::addPlayer(string player) {
  resizeLeaderBoard();
  LBFile.open(file, ios::app);
  if(!LBFile){

      cout << endl << endl;
      cout << "Error: File not opened";
      cout << endl << endl;
  }
  else{

      LBFile << player << " " << 0 << "\n";
      LBFile.close();
  }

}

void leaderBoard::printLeaderboard() {
    string line;
    cout << "Player" << "                        " << "Wins" << endl;
    cout << "------" << "                        " << "----" << endl;
    ifstream infile;
    infile.open(file.c_str());
    if(infile.fail()){
         // do error stuff
         cout << endl << endl;
         cout << "Error: File not opened";
         cout << endl << endl;
    }

    else{
        int i = 0;
        clearArray();
        int a;
        while(i < numberOfEntries && infile >> line >> a){

            cout << line;                  // << "       "  << a <<  "\n";
            for(int i = 0; i < (30 - line.length()); i++){
                cout << " ";
            }
            cout << a << "\n";
            i++;
        }

        infile.close();
    }
}

void leaderBoard::updateLeaderboard(string player) {

    clearArray();

    // write values to the array and clear the file.
    setPlayerInfoValues();

    // update the array
    for(int i = 0; i < numberOfEntries; i++){

        if(leaderBoardArray[i].playerName == player){

            leaderBoardArray[i].wins++;
        }

    }

    // sort the array
    sortLeaderBoard();

    // write the leaderboards back to the file.
    LBFile.open(file, ios::app);
    if(LBFile.is_open()){

        for(int i = 0; i < numberOfEntries; i++){
            LBFile << leaderBoardArray[i].playerName << " " << leaderBoardArray[i].wins << "\n";
        }
        LBFile.close();
    }
}


void leaderBoard::setPlayerInfoValues(){

   ifstream infile;
   string line;
   infile.open(file.c_str());
   if(infile.fail()){

       cout << endl << endl;
       cout << "Error: File not opened";
       cout << endl << endl;
   }
   else{
       int i = 0;
       int a;
       while (i < numberOfEntries && infile >> line >> a) {
           leaderBoardArray[i].playerName = line;
           leaderBoardArray[i].wins = a;
           i++;
       }
   }

       // clear the file
       infile.close();
       std::ofstream ofs;
       ofs.open(file, std::ofstream::out | std::ofstream::trunc);
       ofs.close();

}



void leaderBoard::sortLeaderBoard(){

// sort the array in descending order according to the wins.
    string tempString;
    for(int gap=numberOfEntries/2;gap>0;gap/=2)
    {
        for(int i = gap; i < numberOfEntries; i++)
        {
            int temp=leaderBoardArray[i].wins;
            tempString = leaderBoardArray[i].playerName;
            int j;
            for(j=i; j >= gap && leaderBoardArray[j-gap].wins > temp; j-=gap)
            {
                leaderBoardArray[j].wins = leaderBoardArray[j-gap].wins;
                leaderBoardArray[j].playerName = leaderBoardArray[j - gap].playerName;
            }
            leaderBoardArray[j].wins=temp;
            leaderBoardArray[j].playerName = tempString;
        }
    }

    for(int i = 0; i < numberOfEntries/2; i++){
        if(leaderBoardArray[numberOfEntries - i - 1].wins > leaderBoardArray[i].wins){
            int tempI;
            string tempS;
            tempI = leaderBoardArray[numberOfEntries - i - 1].wins;
            leaderBoardArray[numberOfEntries - i - 1].wins = leaderBoardArray[i].wins;
            leaderBoardArray[i].wins = tempI;

            tempS = leaderBoardArray[numberOfEntries - i - 1].playerName;
            leaderBoardArray[numberOfEntries - i - 1].playerName = leaderBoardArray[i].playerName;
            leaderBoardArray[i].playerName = tempS;


        }

    }

}

void leaderBoard::clearArray(){
    for(int i = 0; i < numberOfEntries; i++){
        leaderBoardArray[i].playerName = "";
        leaderBoardArray[i].wins = 0;
    }
}

int leaderBoard::findNumberOfEntries() {
    int count = 0;
    string line;
    int a;
    ifstream infile;
    infile.open(file.c_str());
    if(infile.fail()){
        cout << endl << endl;
        cout << "Error: File not opened in find number of entries function";
        cout << endl << endl;
    }
    while(infile >> line >> a){
        count++;
    }
    line = "";
    infile.close();

    return count;
}

void leaderBoard::resizeLeaderBoard(){

    numberOfEntries += 1;
    temp = new playerInfo[numberOfEntries];
    for(int i = 0; i < numberOfEntries - 1; i++){

        temp[i].playerName = leaderBoardArray[i].playerName;
        temp[i].wins = leaderBoardArray[i].wins;

    }

    temp[numberOfEntries - 1].playerName = "";
    temp[numberOfEntries - 1].wins = 0;
    delete [] leaderBoardArray;
    leaderBoardArray = new playerInfo[numberOfEntries];
    for(int i = 0; i < numberOfEntries; i++){

        leaderBoardArray[i].playerName = temp[i].playerName;
        leaderBoardArray[i].wins = temp[i].wins;
    }


    delete [] temp;

}

bool leaderBoard::playerExists(string player) {
    string line;
    int a;
    ifstream infile;
    bool exists = false;
    int pos;
    infile.open(file.c_str());
    if (infile.fail()) {

        cout << endl << endl;
        cout << "Error: File not opened";
        cout << endl << endl;
    }
    else {
        int i = 0;
        while ((i < numberOfEntries && infile >> line >> a) && !exists) {

            pos = line.find(player);
            if(pos != std::string::npos) {
                exists = true;
            }

            i++;
        }


    }

  return exists;
}

