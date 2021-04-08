/***************************************************************************
 * Name: Prathamjeet Singh
 *
 * Completed on December 11 2019, 1:10AM
 *
 * Function:  This is class Monster's header
 *
 * Input:    No user input is required in this program.
 *
 * Output:   No output from this class or header
 ***************************************************************************/
#ifndef MONSTER_H
#define MONSTER_H

class Monster
{
public:
  Monster();
  int getHP();
  char getNN();
  int getDamage();
protected:
  int nickName;
  int pick[4] = {50, 100, 150, 200};
  int pickD[3] = {50,75,100};
  int damage;
  int hp;
};

#endif // MONSTER_H
