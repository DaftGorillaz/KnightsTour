#include "TourBoard.h"
#include <iostream>

using namespace std;
//All Code must not go beyond this! (As instructed in Sir's Syllabus.)

TourBoard::TourBoard()
{
  cout << "Starting...\n" << endl;
  for(int a=0;a<64;a++)
  {
    Visit[a] = 0;
  }
  initializeBoard();
}

void TourBoard::initializeBoard() //Makes the Board
{
  cout << "Making the Board...\n" << endl;
  for(int i = 0; i < 64; i++)
  {
    if(i==0||i==7||i==63||i==56)
      board[i] = 2;
    else if(i==1||i==6||i==8||i==15||i==48||i==55||i==57||i==62)
      board[i] = 3;
    else if(i>1&&i<6||i%8==0||(i+1)%8==0||
    i>57&&i<62||i==9||i==14||i==49||i==54)
      board[i] = 4;
    else if((i>9&&i<14)||(i>49&&i<54)||(i-1)%8==0||(i-6)%8==0)
      board[i] = 6;
    else
      board[i] = 8;
  }
  cout << "Empty board made!\n Here:\n";
  //Just printing it out for reference
  cout << "-----------------------------------------\n";
  int Count = 0;
  for(int row=0;row<8;row++)
  {
    for(int col=0;col<8;col++)
    {
      if(board[Count]<10)
        cout << "| 0" << board[Count] << " ";
      else
        cout << "| " << board[Count] << " ";
      Count++;
    }
    cout << "|\n" << "-----------------------------------------\n";
  }
  cout << endl;
}

void TourBoard::StartingPoint(int element)
{
  //Gets coordinates from main and puts the Knight there!
  Move = 1;
  Visit[element] = Move;
  OldSteps = board[element];
  board[element] = 0;
  NextStep(element);
}

void TourBoard::Reduce(int element)
{
  int New;
  for(int a=0;a<8;a++)
  {
    New = element + KnightMoves[a];
    if(New>=0&&New<64)
    {
      switch (a)
      {
      case 0://2 up, 1 left
        if((element<17||element%8==0)||board[New]<2)
          break;
        else
          board[New]--;
          break;
      case 1://2 up, 1 right
        if((element<16||(element-7)%8==0)||board[New]<2)
          break;
        else
          board[New]--;
          break;
      case 2://1 up, 2 right
        if((element<8||(element-7)%8==0||(element-6)%8==0)||board[New]<2)
          break;
        else
          board[New]--;
          break;
      case 3://1 down, 2 right
        if((element>55||(element-7)%8==0||(element-6)%8==0)||board[New]<2)
          break;
        else
          board[New]--;
          break;
      case 4://2 down, 1 right
        if((element>46||(element-7)%8==0)||board[New]<2)
          break;
        else
          board[New]--;
          break;
      case 5://2 down, 1 left
        if((element>47||element%8==0)||board[New]<2)
          break;
        else
          board[New]--;
          break;
      case 6://1 down, 2 left
        if((element>55||element%8==0||(element-1)%8==0)||board[New]<2)
          break;
        else
          board[New]--;
          break;
      case 7://1 up, 2 left
        if((element<10||element%8==0||(element-1)%8==0)||board[New]<2)
          break;
        else
          board[New]--;
          break;
      }
    }
  }
}

void TourBoard::printBoard(ostream& cout)
{
  cout << "-----------------------------------------\n";
  int Count = 0;
  for(int row=0;row<8;row++)
  {
    for(int col=0;col<8;col++)
    {
      if(Visit[Count]<10)
        cout << "| 0" << Visit[Count] << " ";
      else
        cout << "| " << Visit[Count] << " ";
      Count++;
    }
    cout << "|\n" << "-----------------------------------------\n";
  }
  cout << endl;
}

int TourBoard::WhereToGo(int element)
{
  int b=0, Moves[8], New, Least;

  for(int c=0;c<8;c++)
    Moves[c] = 10;

  for(int a=0;a<8;a++)
  {
    New = element + KnightMoves[a];
    if(New>=0&&New<64)
    {
      switch (a)
      {
      case 0://2 up, 1 left
        if((element<17||element%8==0)||board[New]==0)
          break;
        else
          Moves[b] = board[New];
          b++;
          break;
      case 1://2 up, 1 right
        if((element<16||(element-7)%8==0)||board[New]==0)
          break;
        else
          Moves[b] = board[New];
          b++;
          break;
      case 2://1 up, 2 right
        if((element<8||(element-7)%8==0||(element-6)%8==0)||board[New]==0)
          break;
        else
          Moves[b] = board[New];
          b++;
          break;
      case 3://1 down, 2 right
        if((element>55||(element-7)%8==0||(element-6)%8==0)||board[New]==0)
          break;
        else
          Moves[b] = board[New];
          b++;
          break;
      case 4://2 down, 1 right
        if((element>46||(element-7)%8==0)||board[New]==0)
          break;
        else
          Moves[b] = board[New];
          b++;
          break;
      case 5://2 down, 1 left
        if((element>47||element%8==0)||board[New]==0)
          break;
        else
          Moves[b] = board[New];
          b++;
          break;
      case 6://1 down, 2 left
        if((element>55||element%8==0||(element-1)%8==0)||board[New]==0)
          break;
        else
          Moves[b] = board[New];
          b++;
          break;
      case 7://1 up, 2 left
        if((element<10||element%8==0||(element-1)%8==0)||board[New]==0)
          break;
        else
          Moves[b] = board[New];
          b++;
          break;
      }
    }
  }

  Least = Moves[0];
  for(int d=0; d<8; d++)
    if(Moves[d]<Least)
      Least = Moves[d];
  return Least;
}

bool TourBoard::Success()
{
  if(Move<64)
    return false;
  else
    return true;
}

void TourBoard::NextStep(int element)
{
  Reduce(element);//Since we take up a space, reduce number of possible spaces the knight can go to at a specific coordinate
  int BestLocVal = WhereToGo(element);//Finds Location of next move
  int New;
    for(int a=0;a<8;a++)
    {
      New = element + KnightMoves[a];
      if(New>=0&&New<64)
      {
        switch (a)
        {
        case 0://2 up, 1 left
          if((element<17||element%8==0)||board[New]==0)
            break;
          else
            if(BestLocVal==board[New])
              {
                cout << Move << ") Moved 2 up and 1 left!\n";
                Move++;
                Visit[New] = Move;
                OldSteps = board[New];
                board[New] = 0;
                NextStep(New);
              }
            break;
        case 1://2 up, 1 right
          if((element<16||(element-7)%8==0)||board[New]==0)
            break;
          else
            if(BestLocVal==board[New])
              {
                cout << Move << ") Moved 2 up and 1 right!\n";
                Move++;
                Visit[New] = Move;
                OldSteps = board[New];
                board[New] = 0;
                NextStep(New);
              }
            break;
        case 2://1 up, 2 right
          if((element<8||(element-7)%8==0||(element-6)%8==0)||board[New]==0)
            break;
          else
            if(BestLocVal==board[New])
              {
                cout << Move << ") Moved 1 up and 2 right!\n";
                Move++;
                Visit[New] = Move;
                OldSteps = board[New];
                board[New] = 0;
                NextStep(New);
              }
            break;
        case 3://1 down, 2 right
          if((element>55||(element-7)%8==0||(element-6)%8==0)||board[New]==0)
            break;
           else
            if(BestLocVal==board[New])
              {
                cout << Move << ") Moved 1 down and 2 right!\n";
                Move++;
                Visit[New] = Move;
                OldSteps = board[New];
                board[New] = 0;
                NextStep(New);
              }
            break;
        case 4://2 down, 1 right
          if((element>46||(element-7)%8==0)||board[New]==0)
            break;
          else
            if(BestLocVal==board[New])
              {
                cout << Move << ") Moved 2 down and 1 right!\n";
                Move++;
                Visit[New] = Move;
                OldSteps = board[New];
                board[New] = 0;
                NextStep(New);
              }
            break;
        case 5://2 down, 1 left
          if((element>47||element%8==0)||board[New]==0)
            break;
          else
            if(BestLocVal==board[New])
              {
                cout << Move << ") Moved 2 down and 1 left!\n";
                Move++;
                Visit[New] = Move;
                OldSteps = board[New];
                board[New] = 0;
                NextStep(New);
              }
            break;
        case 6://1 down, 2 left
          if((element>55||element%8==0||(element-1)%8==0)||board[New]==0)
            break;
          else
            if(BestLocVal==board[New])
              {
                cout << Move << ") Moved 1 down and 2 left!\n";
                Move++;
                Visit[New] = Move;
                OldSteps = board[New];
                board[New] = 0;
                NextStep(New);
              }
            break;
        case 7://1 up, 2 left
          if((element<10||element%8==0||(element-1)%8==0)||board[New]==0)
            break;
          else
            if(BestLocVal==board[New])
              {
                cout << Move << ") Moved 1 up and 2 left!\n";
                Move++;
                Visit[New] = Move;
                OldSteps = board[New];
                board[New] = 0;
                NextStep(New);
              }
            break;
        }
      }
    }
}

void TourBoard::Animation(int element)
{
  StartingPoint(element);
  int least;
  least = Visit[0];
  for(int a=1; a<64; a++)
  {
    if(Visit[a]<least)
    {
      least = Visit[a];
    }
  }
  if(Success() == false)
  {
    NextStep(element);
  }
  else
  {
    cout << "-----------------------------------------\n";
    int Count = 0;
    for(int row=0;row<8;row++)
    {
      for(int col=0;col<8;col++)
      {
        if(Visit[Count]<10)
        {
          cout << "| 0" << Visit[Count] << " ";
        }
        else
        {
          cout << "| " << Visit[Count] << " ";
        }
        Count++;
      }
      cout << "|\n" << "-----------------------------------------\n";
    }
    cout << endl;
  }
}

void TourBoard::Interactive(int element)
{
  StartingPoint(element);

  cout << "-----------------------------------------\n";
  for(int row=0; row<8; row++)
  {
    for(int col=0; col<8; col++)
    {

    }
  }


  char userInput;

  cout << "Press enter to show next move.\n";
  cin >> userInput;

}

void TourBoard::Immediate(int element)
{
  StartingPoint(element);

  if(Success() == false)
  {
    NextStep(element);
  }
  else
  {
    printBoard(cout);
  }
}
