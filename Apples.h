/***************************************************************************
 * Name: Prathamjeet Singh
 *
 * Completed on December 11 2019, 1:10AM
 *
 * Function:  This is class Apple's header
 *
 * Input:    No user input is required in this program.
 *
 * Output:   No output from this class or header
 ***************************************************************************/
#ifndef APPLES_H
#define APPLES_H

/*
 * Apple header file
 */
class Apples
{
public:
  Apples();
  int getChange();
  char getNN();
private:
  int health;
  int pick[3] = {10,20,30};
  char nickName;
};

#endif // APPLES_H
