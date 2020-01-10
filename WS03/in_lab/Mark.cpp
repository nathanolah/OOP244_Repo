// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 24, 2019

// Mark.cpp implementation file contains the necessary function definitions
// needed for the input and output of validated values used for the Mark module.

#include <iostream> // Includes standard input and output stream
using namespace std; 
#include "Mark.h" // Includes class Mark's data members with member functions and constant int values

namespace sdds
{  
   // Clears buffer
   void Mark::flushKeyboard()const { 
      cin.clear(); 
      cin.ignore(1000, '\n'); // Removes up to specified number of characters, or up to newline delimiter
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
   }

   // Returns boolean true, if Mark object is empty
   bool Mark::isEmpty()const { 
      return m_displayMode == DSP_UNDEFINED 
         && m_mark == -1 
         && m_outOf == 100; 
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
      if (cin.fail() || slash != '/') { // cin.fail() returns boolean value if input was a number, and if slash is not equal to slash 
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
   ostream& Mark::display()const {
      if (isEmpty()) {
         return cout << "Empty Mark object!";
      } 
      else if (m_displayMode == DSP_RAW) {
         cout << rawValue();
      }
      else if (m_displayMode == DSP_PERCENT) {
         cout << "%" << percent();
      }
      else if (m_displayMode == DSP_ASIS) {
         cout << m_mark << "/" << m_outOf;
      }
      else if (m_displayMode == DSP_UNDEFINED) {
         cout << "Display mode not set!";
      } 
      else { 
         cout << "Invalid Mark Display setting!";
      }

      return cout;
   }
}