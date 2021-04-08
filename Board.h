/***************************************************************************
 * Name: Prathamjeet Singh
 *
 * Completed on December 11 2019, 1:10AM
 *
 * Function:  This is class Board's header
 *
 * Input:    No user input is required in this program.
 *
 * Output:   Most of the printing will be done from this class
 ***************************************************************************/
#ifndef BOARD_H
#define BOARD_H
#include "world.h"
#include "Human.h"
#include "Monster.h"
#include "Apples.h"

class Board : public World
{
public:
  Board();
  void fillGrid();
  void initGrid();
  void PrintGrid();
  void UpdateGrid();
  int CountHuman();
  int CountMonster();

protected:
  void printBorder();
  void insert(char, int, int);
  void emptyGrid(int, int);
  void copy(int, int, int, int);
  void fight(int, int, int, int);
  void doDamage(int, int, int, int);
  bool checkBounds(int, int);
  void setMoved();
  void updateBox();
  void Count();
  void printLines();
  int pick[2] = {1,-1};   //Used to pick the new location object want to move to
  int placeApple = 50, placeHuman = 25, placeMonster = 12;    //number of apples, humans and monster that will be spawned on the board
  int MCount, HCount; //Used by winner declaring functions
};

#endif // BOARD_H
