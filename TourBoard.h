#ifndef TOURBOARD_H
#define TOURBOARD_H
#include <iostream>

using namespace std;

class TourBoard
{
  public:
    TourBoard();
    void StartingPoint(int);
    void Animation(int);
    void Interactive(int);
    void Immediate(int);
  private:
    bool Success();
    void Reduce(int);
    int WhereToGo(int);
    void printBoard(ostream&);
    void initializeBoard();
    void NextStep(int);
    int board[64], Move, Visit[64], OldSteps;
    const int KnightMoves[8] = {-17,-15,-6,10,17,15,6,-10};
};

#endif // TOURBOARD_H
