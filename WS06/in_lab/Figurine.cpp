// Figurine.cpp
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 1, 2019 

#define _CRT_SECURE_NO_WARNINGS // To disable deprecation 
#include <iostream>
using namespace std;
#include <cstring> // For strlen() and strcpy()
#include "Figurine.h" // Includes constant values and class Figurine 
namespace sdds
{  
   // Special member functions 
   // Default Constructor
   Figurine::Figurine():m_pose(nullptr), m_price(0) {
      // Set to safe empty state 
      setEmpty();
   }

   // 3-Argument Constructor
   Figurine::Figurine(const char* name, const char* pose, double price) {
      // Set to empty state
      setEmpty();

      // Checks for invalid parameters 
      if (name == nullptr || name[0] == 0 || pose == nullptr) {
         // Set to a safe empty state
         setEmpty();
      }
      else {
         // Set the values to the newly created object
         setName(name);
         setPose(pose);
         setPrice(price);
      }
   }

   // Copy constructor
   // Copies the right operand object to a newly created object 
   Figurine::Figurine(const Figurine& RO) {
      // Sets the values of the newly created object
      setName(RO.m_name);
      setPrice(RO.m_price);
      if (RO.m_pose == nullptr) {
         m_pose = nullptr;
      }
      else {
         setPose(RO.m_pose);
      }
   }
   
   // Destructor
   Figurine::~Figurine() {
      delete[] m_pose; // Deallocate m_pose before going out of scope 
   }

   // Sets data members to a safe empty state 
   void Figurine::setEmpty() {
      *m_name = 0;
      m_pose = nullptr;
      m_price = 0;
   }

   // Bool operator
   // If "m_name" is in an empty state, returns true
   Figurine::operator bool()const {
      return *m_name == 0; 
   }
   
   // Member functions
   // Sets the value of "m_name" from the given parameter
   void Figurine::setName(const char* name) {
      // Checks if the length of the string is within the limit
      if (strlen(name) > MAX_NAME_LEN) {
         strncpy(m_name, name, MAX_NAME_LEN + 1); // Copies and sets the length to MAX_NAME_LEN
      }
      else {
         strcpy(m_name, name); 
      }
   }

   // Allocates memory and sets "m_pose" from the given parameter
   void Figurine::setPose(const char* pose) {
      m_pose = nullptr;
      m_pose = new char[strlen(pose) + 1]; // Allocate memory based on length of "pose" + 1 for nullbyte
      strcpy(m_pose, pose);
   }
   
   // Validates and sets value of m_price 
   void Figurine::setPrice(double price) {
      if (price < 1) {
         price = DEFAULT_PRICE;
      }
      m_price = price;
   }
   
   // Outputs the values of the implicit object
   ostream& Figurine::display()const {
      // Checks if in empty state
      if (operator bool()) { // operator bool returns the state  
         cout << "This Figurine has not yet been sculpted" << endl;
      }
      else {
            cout << "Figurine Details" << endl
            << "Name: " << m_name << endl
            << "Pose: " << m_pose << endl
            << "Price: ";
         cout.setf(ios::fixed); // Set to fixed format 
         cout.precision(2); // Output the value to 2 decimal places 
         cout << m_price << endl;
      }

      return cout;
   }

}