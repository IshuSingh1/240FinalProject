/***************************************************************************
 * Name: Prathamjeet Singh
 *
 * Completed on December 11 2019, 1:10AM
 *
 * Function:  This is class Type's header
 *
 * Input:    No user input is required in this program.
 *
 * Output:   No output from this class or header
 ***************************************************************************/
#ifndef TYPE_H
#define TYPE_H

class Type
{
public:
  Type();
  ~Type();
  Type operator+(Type);
  Type operator-(Type);
  void insert(char, int, int);
  char getName();
  int getHealth();
  void setHealth(int);
  int getDamage();
  void setDamage(int);
  void addMoved();
  void setMoved(int);
  int moved();
  void setName(char);
  int getHeal();
  void setHeal(int);
private:
  char name;
  int x,y;
  int health;
  int move;
  int damage;
  int heal;
};

#endif // TYPE_H
