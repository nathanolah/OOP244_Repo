// Parts.cpp
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 8, 2019 

#include "Parts.h" // Include Parts.h MIN_FORCE and class Arms
namespace sdds
{  
   // Constructor to set Arms object to an empty state 
   Arms::Arms() {
      m_force = 0;
   }

   // One argument constructor to set the value of m_force 
   Arms::Arms(int armsForce) {
      m_force = (armsForce < 1) ? MIN_FORCE : armsForce;
   }

   // Arms destuctor 
   Arms::~Arms() {

   }

   // Returns the force of the Arms object 
   int Arms::getForce()const {
      return m_force;
   }

   // Prefix increment for m_force, and returns the current object 
   Arms& Arms::operator++() {
      m_force += 10;
      return *this; // return the current object
   }

   // Postfix increment for m_force, a copy of the original is returned 
   Arms Arms::operator++(int) {
      Arms copy = *this; // saves the original 
      m_force += 10;
      return copy;
   }

   // Postfix increment for m_force, returns the current object 
   Arms& Arms::operator+=(int val) {
      m_force += val;

      if (m_force < 1) { // checks if val is less than 1 
         m_force = 0;
      }

      return *this; // return the current object
   }
}
