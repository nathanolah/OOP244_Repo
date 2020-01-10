// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 28, 2019

// ReportsUtils.cpp implementation file containing the function 
// definitions for overloaded read() functions and line() function

#include <iostream> // Includes input and output stream
using namespace std;
#include "ReportsUtils.h" // Includes function prototypes
namespace sdds 
{
   // Reads a string from the console up to "len" characters 
   // if the user enters more then "len" characters, the keyboard
   // is flushed and an error message is displayed 
   void read(char* str, int len, const char* errorMessage) {
      bool ok;
      do {
         ok = true;
         cin.getline(str, len + 1, '\n');
         if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
         }
      } while (!ok && cout << errorMessage);
   }

   // Reads an integer referenced by "num" argument
   // if the user enters an invalid integer, the keyboard is flushed
   // and an error message is displayed 
   void read(int& num, const char* errorMessage) {
      bool ok = true;
      char newline;
      do {
         cin >> num;
         newline = cin.get();
         if (cin.fail() || newline != '\n') {
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
         }
      } while (!ok && cout << errorMessage);
   }

   // Prints up to length characters from the "len" argument
   // and outputs a character from "ch" argument
   ostream& line(int len, char ch) {
      for (int i = 0; i < len; i++, cout << ch);
      return cout;
   }
}