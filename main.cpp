#include <iostream>
#include "TourBoard.h"

//All Code must not go beyond this! (As instructed in Sir's Syllabus.)

using namespace std;

int main()
{
  TourBoard Knight;

  cout << "This is the Knight's Tour! Where should it start?" << endl;
  cout << "Please use proper chess board notation.\n";
  cout << "A to H are labels for columns and 1 to 8 are for rows!\n";
  cout << "The Chess Board Looks like this:\n";
  //We don't HAVE to do this but I want to because
  //This is the PROPER indexes for chess boards
  //Mahirap siya pero lol wala lang
  cout << "-----------------------------------------\n";
  char ColChar;
  for(int row=0;row<8;row++)
  {
    for(int col=0;col<8;col++)
    {
      switch (col)
      {
      case 0:
        ColChar = 'A';
        break;
      case 1:
        ColChar = 'B';
        break;
      case 2:
        ColChar = 'C';
        break;
      case 3:
        ColChar = 'D';
        break;
      case 4:
        ColChar = 'E';
        break;
      case 5:
        ColChar = 'F';
        break;
      case 6:
        ColChar = 'G';
        break;
      case 7:
        ColChar = 'H';
        break;
      }
      cout << "| " << ColChar << 8 - row << " ";
    }
    cout << "|\n" << "-----------------------------------------\n";
  }
  int Row = 0, Column = 0;
  GetCol:
  cout << "Col : ";
  cin >> ColChar;
  switch(ColChar)
  {
  case 'a':
  case 'A':
    Column = 0;
    break;
  case 'b':
  case 'B':
    Column = 1;
    break;
  case 'c':
  case 'C':
    Column = 2;
    break;
  case 'd':
  case 'D':
    Column = 3;
    break;
  case 'e':
  case 'E':
    Column = 4;
    break;
  case 'f':
  case 'F':
    Column = 5;
    break;
  case 'g':
  case 'G':
    Column = 6;
    break;
  case 'h':
  case 'H':
    Column = 7;
    break;
  default:
    cout << "Chess boards only go from A to H! Choose from those!\n";
    goto GetCol;
  }
  GetRow:
  cout << "Row : ";
  cin >> Row;
  if(!(Row>0&&Row<9))
  {
    cout << "Please choose a value from 1 to 8 ONLY!" << endl;
    goto GetRow;
  }

  int Elem = 8 * (8 - Row) + Column;

  cout << "OK! We start in " << ColChar << Row << "!\n" << endl;

  //How the board is printed
  Display:
  cout << "How do you want to display the Knights Tour?" << endl;
  cout << "1 - Immediately\n";
  cout << "2 - Animated\n";
  cout << "3 - Interactively\n";
  char displayInput;
  cin >> displayInput;
  cout << endl;

  if(displayInput == '1')
  {
    cout << "You have chosen 1 - Immediately\n" << endl;
    Knight.Immediate(Elem);
  }
  else if(displayInput == '2')
  {
    Knight.Animation(Elem);
  }
  else if(displayInput == '3')
  {
    Knight.Interactive(Elem);
  }
  else
  {
    cout << "Invalid Option. Please select 1, 2, or 3\n" << endl;
    goto Display;
  }

  cout << "Tour finished.";
  return 0;
}
