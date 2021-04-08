/***************************************************************************
 * Name: Prathamjeet Singh
 *
 * Completed on December 11 2019, 1:10AM
 *
 * Function:  This is class Type
 *
 * Input:    No user input is required in this program.
 *
 * Output:   No output from this class or header
 ***************************************************************************/
#include "Type.h"

/*
 * Type default constructor
 */
Type::Type()
{
  move = 0;
  damage = -1;
  health = -1;
  name = '-';
  heal = 0;
}
//Destructor
Type::~Type()
{

}
/*
 * +operator overloading to add the healing to human's total health
 */
Type Type::operator +(Type obj)
{
  Type t;
  t.setMoved(moved());
  t.setName(getName());
  t.setDamage(getDamage());
  t.setHealth(getHealth()+obj.getHeal());
  return t;
}
/*
 * -operator overloading to subtract the healting from monster's total health
 */
Type Type::operator -(Type obj)
{
  Type t;
  t.setMoved(moved());
  t.setName(getName());
  t.setDamage(getDamage());
  t.setHealth(getHealth()-obj.getHeal());
  return t;
}
/*
 * insert is like alternate constructor that takes in parameters
 * to initialize a object
 */
void Type::insert(char c, int a, int b)
{
  this->name = c;
  this->x = a;
  this->y = b;
  this->health = -1;
  this->damage = -1;
}
//returns name
char Type::getName()
{
  return this->name;
}
//sets name to the parameter
void Type::setName(char c)
{
  name = c;
}
//returns health
int Type::getHealth()
{
  return this->health;
}
//sets health to the parameter
void Type::setHealth(int a)
{
  this->health = a;
}
//adds move which signifies that it has moved in that update grid
void Type::addMoved()
{
  move++;
}
//returns move
int Type::moved()
{
  return move;
}
//sets move to the parameter
void Type::setMoved(int a)
{
  move = a;
}
//returns damage
int Type::getDamage()
{
  return damage;
}
//sets damage to parameter passed in
void Type::setDamage(int d)
{
  damage = d;
}
//returns heal
int Type::getHeal()
{
  return heal;
}
//sets heal to the parameter
void Type::setHeal(int h)
{
  heal = h;
}
