// Nathan Olah 
// Student Number: 124723198
// September 11, 2019

#include <iostream>
#include <iomanip>
#include "tools.h"
using namespace std;

namespace sdds
{
   // displays the user interface menu
   int menu(int noOfSamples) {
      line(28);
      cout << "| No Of Samples: " << setw(5) << setiosflags(ios::left) << noOfSamples << "     |" << endl;
      line(28);
      cout << "| 1- Set Number of Samples |" << endl;
      cout << "| 2- Enter Samples         |" << endl;
      cout << "| 3- Graphs                |" << endl;
      cout << "| 0- Exit                  |" << endl;
      cout << "\\ >                        /";
      goBack(24);

      return getInt(0, 3);
   }

   // moves the cursor backwards
   void goBack(int n) {
      for (int i = 0; i < n; cout << "\b", i++);
   }

   // draw line
   void line(int n, const char* label) {
      cout << "+";
      for (int i = 0; i < n - 2; cout << "-", i++);
      cout << "+";
      if (label) {
         goBack(n - 4);
         cout << label;
      }
      cout << endl;
   }

   // Performs a fool-proof integer entry
   int getInt(int min, int max) {
      int val;
      bool done = false;
      while (!done) {
         cin >> val;
         if (cin.fail()) {
            cin.clear();
            cout << "Bad Number, try again: ";
         }
         else {
            if (val < min || val > max) {
               cout << "Invalid value!" << endl << "The value must be between " << min << " and " << max << ": ";
            }
            else {
               done = true;
            }
         }
         cin.ignore(1000, '\n');
      }
      return val;
   }
}