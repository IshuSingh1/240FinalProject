/***************************************************************************
 * Name: Prathamjeet Singh
 *
 * Completed on December 11 2019, 1:10AM
 *
 * Function:  This is class Monster
 *
 * Input:    No user input is required in this program.
 *
 * Output:   No output from this class or header
 ***************************************************************************/
#include "Monster.h"
#include <cstdlib>
#include <time.h>
/*
 * Monster class
 * Object that will be used in to create attributes of Monster object and store it in type class
 * Picks a random number from an set array which will be the health and damage of monster
 */
Monster::Monster()
{
  nickName = 'M';
  int r = (rand() % 4);
  hp = pick[r];
  r = (rand() % 3);
  damage = pickD[r];
}
int Monster::getHP()
{
  return this->hp;
}
char Monster::getNN()
{
  return this->nickName;
}
int Monster::getDamage()
{
  return damage;
}
