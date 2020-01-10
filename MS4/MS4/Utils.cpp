// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 30, 2019

#include <iostream> 
using namespace std;
#include <cstring>
#include "Utils.h"
namespace sdds
{
   // This function accepts an unsigned integer "value" and validates
   // Validates "value" if its a valid integer, and an integer between min and max values
   void readValue(int& value, int min, int max, const char* ErrorMess) {
      bool ok = false;
      char newline = 0;

      do {
         cin >> value; // cin value
         newline = cin.get(); // extract the last character 
         if (cin.fail() || newline != '\n') {
            ok = false;
            cin.clear(); // clear state of cin.fail()
            cin.ignore(1000, '\n'); // discard up to 1000 characters, or '\n' delimiter
         }
         else {
            if (value < min || value > max) { // validate the range of "value"
               ok = false;
            }
            else {
               ok = true;
            }
         }
      } while (!ok && cout << ErrorMess); // loops back if ok is not true, and displays "ErrorMess"
   }

   // This function accepts an unsigned integer "value" and validates
   // Validates "value" if its a valid integer, and an integer between min and max values
   void readValue(unsigned int& value, unsigned int min, unsigned int max, const char* ErrorMess) {
      bool ok = false;
      char newline = 0;

      do {
         cin >> value; // cin value
         newline = cin.get(); // extract the last character 
         if (cin.fail() || newline != '\n') {
            ok = false;
            cin.clear(); // clear state of cin.fail()
            cin.ignore(1000, '\n'); // discard up to 1000 characters, or '\n' delimiter
         }
         else {
            if (value < min || value > max) { // validate the range of "value"
               ok = false;
            }
            else {
               ok = true;
            }
         }
      } while (!ok && cout << ErrorMess); // loops back if ok is not true, and displays "ErrorMess"
   }

   // Validates character string
   void readString(char* str, int len, const char* errorMessage) {
      bool ok;
      do {
         ok = true;
         cin.getline(str, len + 1, '\n'); // inputs up to "len + 1" characters or '\n' delimiter
         if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
         }
         else if (strlen(str) == 0)
            ok = false;
      } while (!ok && cout << errorMessage);
   }

   // Validates values of long long type 
   void readValue(long long& value, long long min, long long max, const char* ErrorMess) {
      bool ok = false;
      char newline = 0;

      do {
         cin >> value; // cin value
         newline = cin.get(); // extract the last character 
         if (cin.fail() || newline != '\n') {
            ok = false;
            cin.clear(); // clear state of cin.fail()
            cin.ignore(1000, '\n'); // discard up to 1000 characters, or '\n' delimiter
         }
         else {
            if (value < min || value > max) { // validate the range of "value"
               ok = false;
            }
            else {
               ok = true;
            }
         }
      } while (!ok && cout << ErrorMess); // loops back if ok is not true, and displays "ErrorMess"
   }
}
