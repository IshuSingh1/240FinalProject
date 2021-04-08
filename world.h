/***************************************************************************
 * Name: Prathamjeet Singh
 *
 * Completed on December 11 2019, 1:10AM
 *
 * Function:  This is World header
 *
 * Input:    No user input is required in this program.
 *
 * Output:   No output from this class or header
 ***************************************************************************/
#ifndef WORLD_H
#define WORLD_H
#include "Type.h"
#include <cstdlib>
using namespace std;

class World
{

public:
  World() {};

  virtual void PrintGrid() = 0;
  virtual void UpdateGrid() = 0;

protected:
  int day=0;
  Type grid[10][10];
  const int MAX = 10;

  virtual void initGrid() = 0;
  virtual bool checkBounds(int,int) = 0;

};
#endif // WORLD_H
