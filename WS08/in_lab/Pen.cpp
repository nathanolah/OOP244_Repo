// Pen.cpp
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 19, 2019

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>
#include "Pen.h"
namespace sdds
{  
   // Default constructor 
   Pen::Pen(): m_style(nullptr) {
      setEmpty();
   }

   // 2 Argument constructor
   Pen::Pen(const char* style, int ink) {
      int length = 0;

      setEmpty();
      if (style) {
         length = strlen(style);
         m_style = new char[length + 1];
         strcpy(m_style, style);
      }
      else {
         setEmpty();
      }

      if (ink < 1 || ink > 50) {
         m_ink = INK_MAX;
      }
      else {
         m_ink = ink;
      }

   }

   // Destructor
   Pen::~Pen() {
      delete[] m_style; // Deallocate m_style
   }

   // Set to safe empty state
   void Pen::setEmpty() {
      m_style = new char[1];
      m_style[0] = 0;
      m_ink = 0;
   }

   // 
   void Pen::write(const char* cString) {
      int count = 0;
      char space[2] = " ";

      if (m_ink) {
         cout << "Writing out the following: " << cString
            << " with a Pen!" << endl;
      } 
      for (unsigned int i = 0; i < strlen(cString); i++) {
         if (cString[i] != space[0]) {
            count++;
         }
      }

       m_ink -= count * 2;
       if (m_ink < 0) {
          m_ink = 0;
          cout << "We can't write without ink!" << endl;
       }
   }

   // Set the value of m_ink
   void Pen::refill(int ink) {
      m_ink = ink;
      if (m_ink > INK_MAX) {
         m_ink = INK_MAX;
      }
      cout << "Refilling the pen with ink" << endl;
   }

   // Return the the state of Pen
   bool Pen::filled()const {
      return (m_ink);
   }

   // Display Pen's details 
   ostream& Pen::display(ostream& os)const {
      if (strcmp(m_style, "") == 0 && m_ink == 0) { 
         os << "This is an empty Pen" << endl;
      }
      else {
         os << "Pen Details" << endl
            << "Style: " << style() << endl
            << "Ink Remaining: " << ink() << endl;
      }

      return os;
   }

   // Returns m_style
   const char* Pen::style()const {
      return m_style;
   }

   // Return m_ink
   int Pen::ink()const {
      return m_ink;
   }
}

