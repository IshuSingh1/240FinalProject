/***************************************************************************
 * Name: Prathamjeet Singh
 *
 * Completed on December 11 2019, 1:10AM
 *
 * Function:  This is class Apple
 *
 * Input:    No user input is required in this program.
 *
 * Output:   No output from this class or header
 ***************************************************************************/
#include "Apples.h"
#include <cstdlib>
#include <time.h>

/*
 * Apple class
 * Object that will be used in to create attributes of Apple object and store it in type class
 * Picks a random number from an set array which will be the heal ot damage it can do.
 */
Apples::Apples()
{
  nickName = 'A';
  int r = (rand() % 3);
  health = pick[r];
}
int Apples::getChange()
{
  return health;
}
char Apples::getNN()
{
  return nickName;
}
