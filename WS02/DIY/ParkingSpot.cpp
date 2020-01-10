// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 22, 2019

// ParkingSpot.cpp implementation file contains the necessary function
// definitions needed for the input and output of information used within the parking lot's
// parking spot. As well as allocation and deallocation of dynamic memory for char pointer m_makeModel.

#define _CRT_SECURE_NO_WARNINGS // To disable deprecation 

#include <iostream> // For standard input and output stream
using namespace std;
#include <cstring> // For strcpy() and strlen() functions
#include "utils.h" // Includes utils module's read() function
#include "ParkingSpot.h" // Includes struct ParkingSpot and function prototypes 
//#include "ParkingLot.h"

namespace sdds
{  
   // Sets m_licensePlate to an empty string and m_makeModel to a 
   // type safe pointer value known as nullptr.
   void setEmpty(ParkingSpot& spot) {
      spot.m_licensePlate[0] = '\0';
      spot.m_makeModel = nullptr;
   }

   // Checks if m_makeModel of ParkingSpot is null.
   // Returns boolean of the condition.
   bool isEmpty(const ParkingSpot& spot) {
      return spot.m_makeModel == nullptr; 
   }

   // Deallocates dynamic memory in m_makeModel of ParkingSpot.
   // Calls setEmpty() function 
   void freeSpot(ParkingSpot& spot) {
      delete[] spot.m_makeModel; // Deallocates char array for m_modelModel
      setEmpty(spot); 
   }

   // Prints the make and model followed by the license plate number 
   void print(const ParkingSpot& spot) {
      cout << spot.m_makeModel << ", plate number: " << spot.m_licensePlate << endl;
   }

   // Calls read() to input a string up to required amount of characters,
   // if the length of the string is too long an error message is outputted.
   void parkCar(ParkingSpot& spot) {
      char makeModel[61];
      char licensePlate[9];

      // Input make and model
      cout << "Make and Model: ";
      read(makeModel, 60, "Too long, Make and model must be shorter than 60 characters\nRedo Entry: ");

      // Input license plate
      cout << "License Plate: ";
      read(licensePlate, 8, "Too long, license plate must be shorter than 8 characters\nRedo Entry: ");

      // Copies licensePlate string into spot.m_licensePlate
      strcpy(spot.m_licensePlate, licensePlate); 

      // Allocates dynamic memory for char array spot.m_makeModel
      spot.m_makeModel = new char[strlen(makeModel) + 1]; // Returns character length of makeModel, plus one for null terminator 
      strcpy(spot.m_makeModel, makeModel); // Copies makeModel string into spot.m_makeModel
   }
}