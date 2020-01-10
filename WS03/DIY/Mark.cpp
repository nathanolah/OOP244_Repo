// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 26, 2019

// Mark.cpp implementation file contains the necessary function definitions
// needed for the input and output of validated values used for the Mark module.

#define _CRT_SECURE_NO_WARNINGS 

#include <iostream> // Includes standard input and output stream
#include <cstring> // For strcpy() and strlen()
using namespace std;
#include "Mark.h" // Includes class Mark's data members with member functions and constant int values

namespace sdds
{
   // Clears buffer
   void Mark::flushKeyboard()const {
      //while (cin.get() != '\n');
      cin.clear();
      cin.ignore(1000, '\n');
   }

   // Sets member variable m_displayMode to the incoming argument displayMode
   void Mark::set(int displayMode) {
      m_displayMode = displayMode;
   }

   // Sets member variables m_mark and m_outOf to the corresponding arguments. 
   // outOf argument has a default value of 1, if an argument is not provided.
   void Mark::set(double mark, int outOf) {
      m_mark = mark;
      m_outOf = outOf;
   }

   // Sets m_displayMode to DSP_UNDEFINED, m_mark to -1,
   // and m_outOf to 100.
   void Mark::setEmpty() {
      m_displayMode = DSP_UNDEFINED;
      m_mark = -1;
      m_outOf = 100;
      m_name[0] = '\0';
   }

   // Returns boolean true, if Mark object is empty
   bool Mark::isEmpty()const {
      return m_mark == DSP_UNDEFINED;
   }

   // Gets the percentage by, dividing m_mark by m_outOf, then multiplies 
   // by 100, then adds 0.5, and casts the value to an int type and returns the value.
   int Mark::percent()const {
      return (int)(0.5 + (100 * (m_mark / m_outOf)));
   }

   // Returns the result of m_mark divided by m_outOf
   double Mark::rawValue()const {
      return m_mark / m_outOf;
   }

   // Reads an inputted mark of a fractional format, cin.get()'s the slash character. cin.fail()
   // check for any other character value other than a number with either a floating-point or integer value.
   // Returns boolean value if the input was valid or invalid.
   bool Mark::read(const char* prompt) {
      char slash;
      char newline;
      bool done = true;

      cout << prompt;
      cin >> m_mark; // Input of mark value
      slash = cin.get(); // Extracts the slash

      if (cin.fail() || slash != '/') { // cin.fail() returns boolean value if input is a number, and if slash is not equal to slash        
         flushKeyboard(); // Clear buffer
         setEmpty();
         done = false;
      }
      else {
         cin >> m_outOf; // Input of mark out of value 
         newline = cin.get();
         if (cin.fail() || newline != '\n') { 
            flushKeyboard();
            setEmpty();
            done = false;
         }
      }

      return done;
   }

   // Checks for value of m_displayMode, depending on the value of m_displayMode 
   // a specified sequence will occur, else the next condition will be evaluated.
   // Returns the object cout.
   ostream& Mark::display(int width)const {
      if (m_name[0] != '\0') {

         cout.setf(ios::left); // Sets a formatting flag, aligned left 
         cout.width(width); // Sets the field width 
         cout.fill('.'); // Sets the padding character 
         cout << m_name;
         //cout.unsetf(ios::left); // Unsets a formatting flag, aligned left
      }
      if (isEmpty()) {
         cout << "Empty Mark object!";
      }
      else {
         if (m_displayMode == DSP_RAW) {
            cout.setf(ios::fixed);
            cout.precision(2); // Counts to the number of 2 significant digits 
            cout << rawValue();
         }
         else if (m_displayMode == DSP_PERCENT) {
            cout << "%" << percent();
         }
         else if (m_displayMode == DSP_ASIS) {
            cout.precision(1);
            cout << m_mark << "/" << m_outOf;
         }
         else if (m_displayMode == DSP_UNDEFINED) {
            cout << "Display mode not set!";
         }
         else if (m_displayMode == DSP_LETTER) { // Outputs Letter
            prnLetter();
         }
         else if (m_displayMode == DSP_GPA) {
            cout.setf(ios::fixed); // Sets fixed format 
            cout.precision(1);
            cout << GPA(); // Outputs GPA 
         }
         else {
            cout << "Invalid Mark Display setting!";
         }
      }

      return cout;

   }

   // Checks the percentage of the mark, and outputs the letter grade 
   void Mark::prnLetter()const {
      int amount = percent();

      if (!isEmpty()) {
         if (amount >= 0 && amount <= 49) {
            cout << "F";
         }
         else if (amount >= 50 && amount <= 54) {
            cout << "D";
         }
         else if (amount >= 55 && amount <= 59) {
            cout << "D+";
         }
         else if (amount >= 60 && amount <= 64) {
            cout << "C";
         }
         else if (amount >= 65 && amount <= 69) {
            cout << "C+";
         }
         else if (amount >= 70 && amount <= 74) {
            cout << "B";
         }
         else if (amount >= 75 && amount <= 79) {
            cout << "B+";
         }
         else if (amount >= 80 && amount <= 89) {
            cout << "A";
         }
         else if (amount >= 90 && amount <= 100) {
            cout << "A+";
         }
         else if (amount > 100) {
            cout << "?";
         }
      }
   }

   // Copies string into m_name 
   void Mark::set(const char* name) {
      strcpy(m_name, name);
   }

   // Sets the name, and sets the m_mark and m_outOf variables
   void Mark::set(const char* name, double rawMark, int outOf) {
      set(name);
      set(rawMark, outOf);
   }

   // Checks the limit of inputted characters, cin is cleared 
   bool Mark::readName(const char* prompt, int maxLen) {
      bool ok = true;
      char newline;
      int length;

      cout << prompt;
      cin >> m_name;
      newline = cin.get();
      if (cin.fail() || newline != '\n') { // Checks if m_name is not a char type, returns boolean
         ok = false;
         cin.clear();
         flushKeyboard();
         setEmpty(); // Sets data members to an empty state
      }
      else {
         length = strlen(m_name); // Get string length 
         ok = length <= maxLen;
      }

      return ok;
   }

   // Adjusts the value of m_outOf member variable
   void Mark::changeOutOf(int value) {
      double ratio = (double)value / m_outOf;

      m_mark *= ratio;
      m_outOf = value;

      if (value < 1) setEmpty();
   }

   // Returns the GPA value of the mark 
   double Mark::GPA()const {
      return rawValue() * 4;
   }

   // Returns the GPA value of the mark based off the grade letter 
   double Mark::letterBasedGPA()const {
      double GPA = 0.0;
      int amount = percent();

      if (amount >= 0 && amount <= 49) {
         GPA = 0.0;
      }
      else if (amount >= 50 && amount <= 54) {
         GPA = 1.0;
      }
      else if (amount >= 55 && amount <= 59) {
         GPA = 1.5;
      }
      else if (amount >= 60 && amount <= 64) {
         GPA = 2.0;
      }
      else if (amount >= 65 && amount <= 69) {
         GPA = 2.5;
      }
      else if (amount >= 70 && amount <= 74) {
         GPA = 3.0;
      }
      else if (amount >= 75 && amount <= 79) {
         GPA = 3.5;
      }
      else if (amount >= 80 && amount <= 89) {
         GPA = 4.0;
      }
      else if (amount >= 90 && amount <= 100) {
         GPA = 4.0;
      }

      return GPA;
   }
}