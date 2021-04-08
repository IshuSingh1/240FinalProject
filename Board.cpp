/***************************************************************************
 * Name: Prathamjeet Singh
 *
 * Completed on December 11 2019, 1:10AM
 *
 * Function:  This is class Board
 *
 * Input:    No user input is required in this program.
 *
 * Output:   Most of the printing will be done from this class
 ***************************************************************************/
#include <iostream>
#include "Board.h"
#include <iomanip>
using namespace std;

//Default Constructor
Board::Board()
{

}
//Insert that will insert an ibject of type on the board
//takes in a character, their yx positions as in integer.
void Board::insert(char c, int a, int b)
{
  grid[a][b].insert(c, a, b);
}

//Initializes the board with just empty objects on the board
//No parameters
void Board::initGrid()
{
  cout << "\n Initializing the box \n";
  for(int i = 0; i < MAX; i++)
    {
      for(int j = 0; j < MAX; j++)
        {
          insert('-', i, j);
        }
    }
}

/*
 *  Fills Grid with random objects
 *  This function is used to fill object type on the board
 *  It will pick random spots that are not already taken
 *  and assign them the new objects to them
 */
void Board::fillGrid()
{
  //Filling Humans on random spots
  srand(time(0));
  int humanCount(0);
  Human h[placeHuman];
  int rJ, rI, i(0);
  while(humanCount<placeHuman)
    {
      rI = (rand() % MAX);
      rJ = (rand() % MAX);
      //Makes sure we are not overriding already filled spot
      if(grid[rI][rJ].getName()=='-')
        {
          insert(h[i].getNN(), rI, rJ);
          //After inserting object, these are the special attributes of that specific class that will be sent to the object
          //If that object does not need that attribute it will be defaulted to 0 or -1 depending on the case.
          grid[rI][rJ].setHealth(h[i].getHP());
          grid[rI][rJ].setDamage(h[i].getDamage());
          grid[rI][rJ].addMoved();
          humanCount++; i++;
          //cout << "Human: " <<grid[rI][rJ].getHealth() << endl;
        }
    }
  //Filling Humans on random spots
  int monsterCount(0);
  Monster m[placeMonster];
  rJ = rI = i = 0;
  while(monsterCount<placeMonster)
    {
      rI = (rand() % MAX);
      rJ = (rand() % MAX);
      //Makes sure we are not overriding already filled spot
      if(grid[rI][rJ].getName()=='-')
        {
          insert(m[i].getNN(), rI, rJ);
          //After inserting object, these are the special attributes of that specific class that will be sent to the object
          //If that object does not need that attribute it will be defaulted to 0 or -1 depending on the case.
          grid[rI][rJ].setHealth(m[i].getHP());
          grid[rI][rJ].setDamage(m[i].getDamage());
          grid[rI][rJ].addMoved();
          monsterCount++; i++;
          //cout << "Monster: "<<grid[rI][rJ].getHealth() << endl;
        }
    }

  //Filling Humans on random spots
  int appleCount(0);
  Apples a[placeApple];
  rJ = rI = i = 0;
  while(appleCount<placeApple)
    {
      rI = (rand() % MAX);
      rJ = (rand() % MAX);
      //Makes sure we are not overriding already filled spot
      if(grid[rI][rJ].getName()=='-')
        {
          insert(a[i].getNN(),rI,rJ);
          //After inserting object, these are the special attributes of that specific class that will be sent to the object
          //If that object does not need that attribute it will be defaulted to 0 or -1 depending on the case.
          grid[rI][rJ].setHeal(a[i].getChange());
          grid[rI][rJ].setHealth(1);
          //This is set to just a random number that is not less than 1
          grid[rI][rJ].setMoved(5);
          grid[rI][rJ].setDamage(1);
          appleCount++; i++;
          //cout << "Apple: "<<grid[rI][rJ].getName() << endl;
        }
    }
}

/*
 * Moves the object around like they are moving everyday
 * Update grid takes in no parameters
 * The objects can move if are in moving to valid bounds
 * and the spot it they are moving on is reachable with 1 step
 */
void Board::UpdateGrid()
{
  setMoved();
  srand(time(0));
  for(int i = 0; i < MAX; i++)
    {
      for(int j = 0; j < MAX; j++)
        {
          if((grid[i][j].getHealth()!=-1)&&grid[i][j].getName()!='-'&&!(grid[i][j].moved()>0))
            {
              //Choosing random location that is 1 step further for the object to move
              int r = (rand() % 2);
              int picked = pick[r];
              int p = i;
              int q = j;
              int rm = (rand()%MAX);
              if(rm ==0)
                p+=picked;
              else if(rm==1)
                {
                  p+=picked;
                  q+=picked;
                }
              else if(rm==2)
                {
                  p-=picked;
                  q-=picked;
                }
              else if(rm==3)
                {
                  p+=picked;
                  q-=picked;
                }
              else if(rm==4)
                {
                  p-=picked;
                  q+=picked;
                }
              else
                q+=picked;
              //If the spot object is moving into have same class object there, it doesnot move
              if(grid[i][j].getName()==grid[p][q].getName())
                {break;}
              //If the spot is out of bounds it does not move
              if(checkBounds(p,q)!=true)
                {break;}
              //If the moving object is Human and the destined object is Monster they call the fight function
              //where the person on his spot get to take the first hit before getting hit.
              else if((grid[i][j].getName()=='H'&&grid[p][q].getName()=='M'))
                {
                  fight(i,j,p,q);
                }
              //If the moving object is Monster and the destined object is Human they call the fight function
              //where the person on his spot get to take the first hit before getting hit.
              else if((grid[i][j].getName()=='M'&&grid[p][q].getName()=='H'))
                {
                  fight(i,j,p,q);
                }
              //If the current object is Human and the destined object is Apple it uses + overloading operator
              //to just heal the human without changing its other attributes
              //Then human moves it in apples place
              else if(grid[i][j].getName()=='H'&&grid[p][q].getName()=='A')
                {
                  grid[i][j] = grid[i][j]+grid[p][q];
                  cout <<"Notice: "<< "Health gained by " << grid[i][j].getName() << " at x: " << j << " y: " <<i << endl;
                  copy(i,j,p,q);
                }
              //If the current object is Monster and the destined object is Apple it used - overloading operator
              //to decrease the health of monster by the apples heal without changing any other attributes
              //Then Monster moves it in its place if left alive
              else if(grid[i][j].getName()=='M'&&grid[p][q].getName()=='A')
                {
                  grid[i][j] = grid[i][j]-grid[p][q];
                  cout <<"Notice: "<< "Health lost by " << grid[i][j].getName() << " at x: " << j << " y: " <<i << endl;
                  copy(i,j,p,q);
                }
              //If the Human just moving to empty spot, it just copies its data to the new spot
              else if((grid[i][j].getName()=='H'&&grid[p][q].getName()=='-'))
                {
                  copy(i,j,p,q);
                }
              //If the Monster just moving to empty spot, it just copies its data to the new spot
              else if((grid[i][j].getName()=='M'&&grid[p][q].getName()=='-'))
                {
                  copy(i,j,p,q);
                }
              //Else should not reach but it is just in case
              else
                copy(i,j,p,q);
            }
        }
    }
}

/*
 * Fight function
 * Takes in the positions of both Human and Monster
 * The staying object gets the advantage of taking the hit first
 */
void Board::fight(int i, int j, int p, int q)
{
  //Keep doing this until one of them have 0 or less health left
  while(grid[i][j].getHealth()>0&&grid[p][q].getHealth()>0)
    {
      doDamage(i,j,p,q);
      if(grid[i][j].getHealth()<=0)
        {
          cout <<"Update: " << grid[i][j].getName() << " at x: " << j << " y: " << i << " destroyed by " << grid[p][q].getName()<< " at x: "<< q << " y: " << p << endl;
          grid[p][q].addMoved();
        }
      else if(grid[p][q].getHealth()<=0)
        {
          cout <<"Update: "<< grid[p][q].getName() << " at x: " << q << " y: " << p << " eliminated by " << grid[i][j].getName()<< " at x: "<< j << " y: " << i << endl;
          copy(i,j,p,q);
        }

    }
}

/*
 * doDamage function
 * Takes in positions of both objects
 * First decreases the health of moving object then if valid
 * the staying object takes the damage
 */
void Board::doDamage(int i, int j, int p, int q)
{
  grid[i][j].setHealth(grid[i][j].getHealth()-grid[p][q].getDamage());
  if(grid[i][j].getHealth()<=0)
    return;
  grid[p][q].setHealth(grid[p][q].getHealth()-grid[i][j].getDamage());
}

/*
 * A function that checks takes in two x and y integers
 * and checks if they are valid on the board or not
 */
bool Board::checkBounds(int a,int b)
{
  if(a<MAX&&a>=0&&b<MAX&&b>=0)
    return true;
  return false;
}

/*
 * Copy function
 * It takes in new positions and old position
 * Copies the old position's object's attributes to the new position and
 * empties the old position;s object;s attrubutes
 */
void Board::copy(int oldx, int oldy, int newx, int newy)
{
  grid[newx][newy].setName(grid[oldx][oldy].getName());
  grid[newx][newy].setMoved(grid[oldx][oldy].moved()+1);
  grid[newx][newy].setHealth(grid[oldx][oldy].getHealth());
  grid[newx][newy].setDamage(grid[oldx][oldy].getDamage());
  grid[newx][newy].addMoved();
  emptyGrid(oldx,oldy);
}

/*
 * EmptyGrid function
 * Just sets attributes to very default which will be considered empty by the program
 */
void Board::emptyGrid(int a, int b)
{
  grid[a][b].setName('-');
  grid[a][b].setHealth(-1);
  grid[a][b].setMoved(0);
  grid[a][b].setDamage(-1);
  grid[a][b].setHeal(0);
}

/*
 * Set moved function
 * This function before every update grid function so we are sure that every Human and Monster object
 * get the chance to move
 */
void Board::setMoved()
{
  for(int i = 0; i < MAX; i++)
    {
      for(int j = 0; j < MAX; j++)
        {
          if(grid[i][j].getName()!='A')
            grid[i][j].setMoved(0);
        }
    }
}

/*
 * This updateBox function is just to clear any left out junk attribute left by accident
 * It runs before every update grid as well
 */
void Board::updateBox()
{
  for(int i = 0; i < MAX; i++)
    {
      for(int j = 0; j < MAX; j++)
        {
          if(grid[i][j].getHealth()<=0||grid[i][j].getDamage()<=0||grid[i][j].getName()=='-')
            {
              emptyGrid(i,j);
            }
        }
    }
}

/*
 * Count functions
 * Determines who is the winner
 * Exits code if the winner is found after couting it
 * Runs after every print
 */
void Board::Count()
{
  MCount=0;
  HCount=0;
  for(int i = 0; i < MAX; i++)
    {
      for(int j = 0; j < MAX; j++)
        {
          if(grid[i][j].getName()=='H')
            HCount++;
          if(grid[i][j].getName()=='M')
            MCount++;
        }
    }
  if(HCount==0&&MCount==0)
    {
      return;
    }
  if(MCount==0)
    {
      cout << "Humans won! Lets go!" << endl;
      exit(1);
    }
  if(HCount==0)
    {
      cout << "Monster Scream Comes, 'Its our world now!'" << endl;
      exit(1);
    }
}
/*
 * These two CountHuman and CountMonster function will be public which will be used by main
 * to determine the winner even if the player choose the leave the simulation earlier
 */
int Board::CountHuman()
{
  HCount=0;
  for(int i = 0; i < MAX; i++)
    {
      for(int j = 0; j < MAX; j++)
        {
          if(grid[i][j].getName()=='H')
            HCount++;
        }
    }
  return HCount;
}
/*
 * These two CountHuman and CountMonster function will be public which will be used by main
 * to determine the winner even if the player choose the leave the simulation earlier
 */
int Board::CountMonster()
{
  MCount=0;
  for(int i = 0; i < MAX; i++)
    {
      for(int j = 0; j < MAX; j++)
        {
          if(grid[i][j].getName()=='M')
            MCount++;
        }
    }
  return MCount;;
}

/********************Printing and Other extra functions********************************/
void Board::printBorder()
{
  cout<<"  +";
  for(int i = 0; i < MAX; i++)
    {
      cout << "---------+";
    }
  cout <<" "<< endl;
}
void Board::PrintGrid()
{
  updateBox();
  cout << "Day: " << day++ << endl;
  cout << " ";
  for(int i = 0; i < MAX; i++)
    {
      cout << "  " << i << "       ";
    }
  cout << endl;
  int count(0);
  printBorder();
  printLines();
  for(int i = 0; i < MAX; i++)
    {   cout << count++ << " ";
      for(int j = 0; j < MAX; j++)
        {
          if(grid[i][j].getName()=='H'||grid[i][j].getName()=='M')
            {
              cout << "|" << setfill('0') << setw(3)<<grid[i][j].getDamage() << " " << grid[i][j].getName() << " ";
              cout << setfill('0') << setw(3)<<grid[i][j].getHealth();
            }
          else if(grid[i][j].getName()=='A')
            {
              cout << "|    " << grid[i][j].getName() << "    ";
            }
          else
            cout << "|    " << grid[i][j].getName() << "    ";
        }
      cout << "|" << endl;
      printLines();
      printBorder();
    }
  Count();
}
void Board::printLines()
{
  cout << "  |";
  for(int i = 0; i < MAX; i++)
    {
      cout << "         |";
    }
  cout << endl;
}


