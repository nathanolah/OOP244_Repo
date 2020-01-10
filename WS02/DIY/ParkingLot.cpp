// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 22, 2019

// ParkingLot.cpp implementation file contains the necessary function
// definitions needed for the functionality of the parking lot. As well
// as the allocation and deallocation of dynamic memory for the amount of parking spots.

#include <iostream> // For standard input and output stream
using namespace std;
#include "ParkingLot.h" // Includes struct ParkingLot and function prototypes

namespace sdds
{  
   // Sets m_numOfParkingSpots to 0, and m_parkingSpot to a
   // type safe pointer value known as nullptr.
   void setEmpty(ParkingLot& senePark) {
      senePark.m_numOfParkingSpots = 0;
      senePark.m_parkingSpot = nullptr;
   }

   // Checks if m_parkingSpot of ParkingLot is null.
   // Returns boolean of the condition.
   bool isEmpty(const ParkingLot& senePark) {
      return senePark.m_parkingSpot == nullptr;
   }

   // Dynamically allocates a number of parking spots and keeps the address
   // in lot.m_parkingSpot. The sets of the elements empty in the call to setEmpty() function.
   void openParking(ParkingLot& senePark, int noOfSpots) {
      int i;

      senePark.m_numOfParkingSpots = noOfSpots;

      // Allocates dynamic memory for an array of parking spots
      senePark.m_parkingSpot = new ParkingSpot[noOfSpots];

      for (i = 0; i < noOfSpots; i++) {
         setEmpty(senePark.m_parkingSpot[i]); // Sets all elements of m_parkingSpot to empty 
      }
   }

   // Checks for the first empty parking spot in the parking lot 
   // if the first index of the character string m_licensePlate is null, 
   // the parking spot is empty. Call to parkCar() to park the car at the index of m_parkingSpot[].
   int parkCar(ParkingLot& senePark) {
      int i;

      for (i = 0; i < senePark.m_numOfParkingSpots; i++) {
         if (senePark.m_parkingSpot[i].m_licensePlate[0] == '\0') {
            parkCar(senePark.m_parkingSpot[i]);

            return i; // Returns index of parking spot 
         }
      }

      return -1; 
   }

   // Checks if the parking spot number is between 0 and number of spots, and checks 
   // boolean value if the parking spot is not empty. If not empty, print() function is called
   // to print the spot, and after to deallocate the spot calling freeSpot().
   bool returnCar(ParkingLot& senePark, int spotNo) { 
      bool done = false;

      if (spotNo >= 0 && spotNo <= senePark.m_numOfParkingSpots && !isEmpty(senePark) && !isEmpty(senePark.m_parkingSpot[spotNo])) {
         cout << "Returning ";
         print(senePark.m_parkingSpot[spotNo]); // Output info on returning car at selected parking spot number 
         freeSpot(senePark.m_parkingSpot[spotNo]);

         done = true;
      }

      return done;
   }

   // Checks for all parking spots that are not empty and returns the car.
   // Deallocates dynamic array of m_parkingSpots, and calls setEmpty() to empty the parking lot.
   void closeParking(ParkingLot& senePark) {
      int i;

      for (i = 0; i < senePark.m_numOfParkingSpots; i++) {
         returnCar(senePark, i);
      }

      // Deallocates dynamic memory for lot.m_parkingSpot
      delete[] senePark.m_parkingSpot;
      setEmpty(senePark);
   }
}