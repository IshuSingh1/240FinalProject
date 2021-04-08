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
#include "Board.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  char c;
  cout << "----------------------------Survival Simulation----------------------------\n\n";
  cout << "HELP: \n1. First a empty board will be initialized.\n2. Humans, Monsters, and Apples will be spawned on Day 1 at "
          "\n   random places with random number of damage, hitpoints, etc.\n3. Humans, Monster, and Apple denoted by 'H' & 'M' & 'A' respectively."
          "\n4. To the left of Humans and Monsters the numbers shown is damage per hit and \n   number to the right is health they are spawned with.\n\n";
  cout << "Maximize the WINDOW Size before starting the simulation to see the whole board\n\n";
  cout << "Press 'y' to start the simulation (y/n): ";
  cin >>c;
  if(c == 'y'||c == 'Y')
    {
      Board b;
      b.initGrid();
      b.PrintGrid();
      b.fillGrid();
      b.PrintGrid();
      while(true)
        {
          cout << "continue the simulation(y/n): " ;
          cin >> c;
          //c='y';
          cout << endl << endl;
          if(c=='y'||c=='Y')
            {
              cout << endl << endl;
              b.UpdateGrid();
              b.PrintGrid();
            }
          else break;
        }
      if(b.CountHuman()==b.CountMonster())
        cout << "Close game. Can call it a tie " << endl;
      else if(b.CountHuman()<=b.CountMonster())
        cout << "Monster were about to take over " << endl;
      else if(b.CountHuman()>=b.CountMonster())
        cout << "Humans had the number game but Monsters are very strong as well" << endl;
    }

  return 0;
}
