// Metal.cpp
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 6, 2019

#define _CRT_SECURE_NO_WARNINGS // To disable deprecation 
#include <iostream> // For ostream and istream
using namespace std;
#include <cstring> // For strlen() and strcpy()
#include "Metal.h" // Includes the derived class Metal and constant values
namespace sdds
{  
   // Default constructor
   Metal::Metal():m_name(nullptr), m_mohs(0) {
      // Set to safe empty state
      setEmpty();
   }

   // 5-Argument constructor, and base class Ore's 3-Argument constructor
   Metal::Metal(double weight, int purity, const char* classification,
      const char* name, double mohs) : Ore(weight, purity, classification) {

      if (name == nullptr || strcmp(name, "") == 0) { 
         // Sets to empty state
         setEmpty();
      }
      else {
         // Allocate and set m_name
         if (strlen(name) > NAME_LEN) {
            m_name = new char[NAME_LEN + 1];
         }
         else {
            m_name = new char[strlen(name) + 1];
         }
         strcpy(m_name, name); 

         // Set m_mohs
         m_mohs = (mohs > 0) ? mohs : DEFAULT_MOHS;
      }
   }

   // Destructor
   Metal::~Metal() {
      delete[] m_name; // Deallocate m_name before going out of scope
   }

   // Sets values to a safe empty state 
   void Metal::setEmpty() {
      m_mohs = 0; 
      m_name = nullptr;
   }

   // If refine() returns true, "m_mohs" is incremented by 1
   void Metal::refine() {
      if (Ore::refine() == true) {
         m_mohs++; 
      }
   }

   // Returns m_name
   const char* Metal::name()const {
      return m_name;
   }

   // Returns m_mohs
   double Metal::mohs()const {
      return m_mohs;
   }

   // Outputs the data members of Metal and Ore's attributes 
   ostream& Metal::display(ostream& os)const { 
      if (name() == nullptr || name() == 0) {
         os << "This metal is imaginary" << endl;
      }
      else {
         os << "Name: " << name() << endl;
         Ore::display(os); // Call to inherited Ore's display 
         os.setf(ios::fixed); // Set to fixed format
         os.precision(2); // Outputs the value to 2 decimal places
         os << "Mohs: " << mohs() << endl;
      }

      return os;
   }

   // Input the values of Metal's and Ore's attributes 
   istream& Metal::input(istream& is) {
      char tempName[NAME_LEN + 1];
      double tempMohs = 0;
      *tempName = 0;

      // Input metal's name
      cout << "Enter a value for this metal's name: ";
      is.getline(tempName, NAME_LEN + 1, '\n');

      if (name() != nullptr) {
         delete[] m_name; // Deallocate m_name if not nullptr
      }

      // Allocate and copy for "m_name"
      m_name = new char[strlen(tempName) + 1];
      strcpy(m_name, tempName);
      
      // Input metal's mohs
      cout << "Enter a value for this metal's mohs: ";
      is >> tempMohs;
      is.clear(); // Clears state to allow further extraction
      is.ignore(1000, '\n'); // Clears input buffer, discards up to 1000 characters or until '\n'
      
      m_mohs = (tempMohs > 0) ? tempMohs : DEFAULT_MOHS;
      Ore::input(is); // Calls Ore's input member function 

      return is;
   }

   // Helper Operator
   // Calls Metal's class display function, and returns os parameter
   ostream& operator<<(ostream& os, const Metal& met) {
      os << "Metal" << endl;
      return met.display(os);
   }

   // Calls Metal's class input function, and returns is parameter
   istream& operator>>(istream& is, Metal& met) {
      return met.input(is);
   }
}
