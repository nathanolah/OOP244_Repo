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
   Figurine::Figurine() :m_pose(nullptr), m_price(0) {
      // Set to safe empty state 
      setEmpty();
   }

   // 3-Argument Constructor
   Figurine::Figurine(const char* name, const char* pose, double price) {
      // Set to safe empty state
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
         m_copy = false; 
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
         m_copy = true;
      }
      else {
         setPose(RO.m_pose);
         m_copy = true;
      }

   }

   // Destructor
   Figurine::~Figurine() {
      delete[] m_pose; // Deallocate m_pose before going out of scope 
   }

   // Sets data members to safe empty state
   void Figurine::setEmpty() {
      *m_name = 0;
      m_pose = nullptr;
      m_price = 0;
      m_copy = false;
   }

   // Bool operator
   // If "m_name" is in an empty state, returns true
   Figurine::operator bool()const {
      return *m_name == 0;
   }

   // Copy assignment operator
   Figurine& Figurine::operator=(const Figurine& RO) {
      if (this != &RO) {
         delete[] m_pose;
         setName(RO.m_name);
         if (RO.m_pose != nullptr) {
            setPose(RO.m_pose);
         }
         setPrice(RO.m_price);
      }
      m_copy = true;

      return *this;
   }

   // Member functions
   // Query function that returns the value of "m_copy"
   bool Figurine::isCopy()const {
      return m_copy;
   }

   // Query function that returns the value of "m_name"
   const char* Figurine::name()const {
      return m_name; 
   }
   
   // Query function that returns the value of "m_pose"
   const char* Figurine::pose()const {
      return m_pose;
   }

   // Query function that returns the value of "m_price"
   double Figurine::price()const {
      return m_price;
   }

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
      if (operator bool() && isCopy()) { // operator bool returns the state  
         cout << "This Figurine has not yet been sculpted" << endl
            << "This is a replica of emptiness" << endl;
      }
      else if (operator bool()) {
         cout << "This Figurine has not yet been sculpted" << endl;
      }
      else if (!operator bool() && isCopy()) {
         cout << "Figurine Details" << endl
            << "Name: " << m_name << endl
            << "Pose: " << m_pose << endl
            << "Price: ";
         cout.setf(ios::fixed); // Set to fixed format 
         cout.precision(2); // Output the value to 2 decimal places 
         cout << m_price << endl
            << "This is a replica" << endl;
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
   
   // Helper function
   // Compares the two Figurines against each other
   // Returns true if the attributes between each other are the same and neither are a copy 
   bool operator==(const Figurine& LO, const Figurine& RO) {
      bool same = true;
      
      // Checks if the reference of the operands are not the same
      if (&LO != &RO) {
         // Checks if each attribute of the object is not the same 
         if (strcmp(LO.name(), RO.name()) != 0) {
            same = false;
         } else if (same && strcmp(LO.pose(), RO.pose()) != 0) {
            same = false;
         } else if (same && LO.price() != RO.price()) {
            same = false;
         } else if (same && (LO.isCopy() == true || RO.isCopy() == true)) {
            same = false;
         }
      }

      return same;
   }
}