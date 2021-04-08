/***************************************************************************
 * Name: Prathamjeet Singh
 *
 * Completed on December 11 2019, 1:10AM
 *
 * Function:  This is class Human
 *
 * Input:    No user input is required in this program.
 *
 * Output:   No output from this class or header
 ***************************************************************************/
#include "Human.h"
#include <cstdlib>
#include <time.h>

/*
 * Human class
 * Object that will be used in to create attributes of Human object and store it in type class
 * Picks a random number from an set array which will be the health and damage.
 */
Human::Human()
{
  nickName = 'H';
  int r = (rand() % 4);
  hp = pick[r];
  r = (rand() % 2);
  damage = pickD[r];
}
int Human::getHP()
{
  return this->hp;
}
char Human::getNN()
{
  return this->nickName;
}
int Human::getDamage()
{
  return damage;
}
