// Ore.cpp
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 3, 2019 

#define _CRT_SECURE_NO_WARNINGS // To disable deprecation 
#include <iostream> 
using namespace std;
#include <cstring> // For strlen() and strcpy()
#include "Ore.h" // Includes constant values and class Ore
namespace sdds
{  
   // Default constructor 
   Ore::Ore() {
      // Sets object to safe empty state
      setEmpty();
   }
   
   // 3-Argument constructor 
   Ore::Ore(double weight, int purity, const char* classification) {
      // Set to safe empty state
      setEmpty();

      // Sets the values of the object
      if (weight < 1) {
         m_weight = DEFAULT_WEIGHT;
      }
      else {
         m_weight = weight;
      }

      if (purity < 1 || purity > 100) {
         m_purity = DEFAULT_PURITY;
      }
      else {
         m_purity = purity;
      }
      
      // Copy "classification" into "m_classification" up to 31 characters 
      strncpy(m_classification, classification, CLASS_LEN + 1);
   }
   
   // Reduces weight to increase purity 
   bool Ore::refine() {
      bool successful = true;
     
      if (m_purity >= 100) { 
         cout << "Can no longer be refined" << endl;
         successful = false;
      }
      else {
         m_weight -= 20;
         m_purity += 10;
         if (m_purity > 100) {
            m_purity = 100;
         }
         successful = true;
      }
    
      return successful;
   }
   
   // Set object to a safe empty state
   void Ore::setEmpty() {
      m_weight = 0;
      m_purity = 0;
      *m_classification = 0;
   }
   
   // Returns m_weight value
   double Ore::weight()const {
      return m_weight;
   }

   // Returns m_purity value
   int Ore::purity()const {
      return m_purity;
   }

   // Returns m_classification string
   const char* Ore::classification()const {
      return m_classification;
   }

   // Displays the current details of the Ore object 
   // Takes in a parameter of ostream type 
   ostream& Ore::display(ostream& os)const { 
      if (weight() == 0) { 
         os << "This ore is imaginary" << endl;
      }
      else {
         os.setf(ios::fixed); // Set to fixed format
         os.precision(2); // Outputs the value to 2 decimal places
         os << "Weight: " << weight() << endl
            << "Purity: " << purity() << endl
            << "Classification: " << classification() << endl;
      }

      return os;
   }

   // Sets the values of the Ore object 
   // Takes a parameter of istream type 
   istream& Ore::input(istream& is) { 
      double tempWeight = 0;
      int tempPurity = 0;
      char tempClassification[CLASS_LEN + 1]; 
   
      cout << "Enter a value for this ore's weight: ";
      is >> tempWeight;
      cout << "Enter a value for the ore's purity: ";
      is >> tempPurity;
      is.ignore(1000, '\n'); 
      cout << "Enter a classification for the ore (MAX 30 chars): ";
      is.getline(tempClassification, CLASS_LEN + 1, '\n'); // Inputs string up to 31 characters or '\n'
      
      // Set values
      set(tempWeight, tempPurity, tempClassification);

      return is;
   }
   
   // Validates and sets the values of an Ore object
   void Ore::set(double tempWeight, int tempPurity, const char* tempClassification) {
      if (tempWeight < 1) {
         m_weight = DEFAULT_WEIGHT;
      }
      else {
         m_weight = tempWeight;
      }

      if (tempPurity < 1 || tempPurity > 100) {
         m_purity = DEFAULT_PURITY;
      }
      else {
         m_purity = tempPurity;
      }
      strcpy(m_classification, tempClassification);
   }
   
   // Helper operators
   // Calls Ore's class display function, and returns os parameter
   ostream& operator<<(ostream& os, const Ore& ore) {
      os << "Ore" << endl;
      return ore.display(os);
   }

   // Calls Ore's class input function, and returns is parameter
   istream& operator>>(istream& is, Ore& ore) {
      return ore.input(is);
   }
}
