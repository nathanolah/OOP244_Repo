// Pencil.cpp
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 19, 2019

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>
#include "Pencil.h"
namespace sdds
{
   // Default constructor
   Pencil::Pencil() {
      setEmpty();
   }

   // 2 Argument constructor
   Pencil::Pencil(const char* HB_scale, int graphite) {
      setEmpty();

      if (HB_scale) {
         strncpy(m_HB_scale, HB_scale, HB_MAX + 1); // Plus one for nullbyte
      }
      else {
         setEmpty();
      }

      if (graphite < 1 || graphite > 100) { // If graphite is not in range
         m_graphite = GRAPHITE_MAX; // set GRAPHITE_MAX
      }
      else {
         m_graphite = graphite;
      }
   }

   // Destructor
   Pencil::~Pencil() {}

   // 
   void Pencil::write(const char* cString) {
      int spaces = 0;
      const char space[2] = " "; 

      if (m_graphite == 0) {
         cout << "We can't write without graphite!" << endl;
      }
      
      if (m_graphite) {
         cout << "Writing out the following: " << cString
            << " with a Pencil!" << endl;

         for (unsigned int i = 0; i < strlen(cString); i++) {
            if (cString[i] == space[0]) {
               spaces++;
            }
         }
         m_graphite -= spaces * 5;
         if (m_graphite < 0) {
            m_graphite = 0;
         }
      }
      
   }

   // 
   void Pencil::refill(int graphite) {
      m_graphite = graphite;
      if (m_graphite > GRAPHITE_MAX) {
         m_graphite = GRAPHITE_MAX;
      }

      cout << "Refilling the pencil with graphite" << endl;
   }

   // Return the boolean state of Pencil
   bool Pencil::filled()const {
      return (m_graphite);
   }

   //
   ostream& Pencil::display(ostream& os)const {
      if (*m_HB_scale == 0 && m_graphite == 0) {
         cout << "This is an empty Pencil" << endl;
      }
      else {
         
         os << "Pencil Details" << endl
            << "HB Value: " << hbScale() << endl
            << "Graphite Remaining: " << graphite() << endl;
      }
      return os;

   }

   // Set to safe empty state
   void Pencil::setEmpty() {
      *m_HB_scale = 0;
      m_graphite = 0;
   }

   // Returns m_HB_scale
   const char* Pencil::hbScale()const {
      return m_HB_scale;
   }

   // Return m_graphite
   int Pencil::graphite()const {
      return m_graphite;
   }
}