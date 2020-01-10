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
      bool ok = true;
      do {
         cin.getline(str, len + 1, '\n'); // Gets string up to "len +1" times, with '\n' delimiter 
         if (cin.fail()) { // Checks for char type
            cin.clear();
            cin.ignore(1000, '\n'); // Discards up to 1000 characters, or '\n' delimiter
            ok = false;
         }
      } while (!ok && cout << errorMessage); // Loops back and displays an error message
   }

   // Reads an integer referenced by "num" argument
   // if the user enters an invalid integer, the keyboard is flushed
   // and an error message is displayed 
   void read(int& num, const char* errorMessage) {
      bool ok = true;
      char newline;
      do {
         cin >> num;
         newline = cin.get(); // Gets the newline 
         if (cin.fail() || newline != '\n') { // cin.fail() checks if num is not an int
            cin.clear();
            cin.ignore(1000, '\n'); 
            ok = false;
         }
      } while (!ok && cout << errorMessage); 
   }

   //void read(int& num, const char* promptMessage, const char* errorMessage) {
   //   bool ok = true;
   //   char newline;

   //   cout << promptMessage;
   //   do {
   //      cin >> num;
   //      newline = cin.get(); // Gets the newline 
   //      if (cin.fail() || newline != '\n') { // cin.fail() checks if num is not an int
   //         cin.clear();
   //         cin.ignore(1000, '\n');
   //         ok = false;
   //      }
   //   } while (!ok && cout << errorMessage);

   // Prints up to length characters from the "len" argument
   // and outputs a character from "ch" argument
   ostream& line(int len, char ch) {
      for (int i = 0; i < len; i++, cout << ch); // iterates "len" times, outputting "ch"
      return cout;
   }
}