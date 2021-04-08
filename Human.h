/***************************************************************************
 * Name: Prathamjeet Singh
 *
 * Completed on December 11 2019, 1:10AM
 *
 * Function:  This is class Human's header
 *
 * Input:    No user input is required in this program.
 *
 * Output:   No output from this class or header
 ***************************************************************************/
#ifndef HUMAN_H
#define HUMAN_H

/*
 * Human Header file
 */
class Human
{
public:
  Human();
  int getHP();
  char getNN();
  int getDamage();
protected:
  int nickName;
  int pick[4] = {25, 50, 75, 100};
  int pickD[2] = {25,50};
  int hp;
  int damage;
};

#endif // HUMAN_H
