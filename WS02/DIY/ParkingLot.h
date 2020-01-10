// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 22, 2019

// ParkingLot.h header file, containing the definition of struct ParkingLot,
// and the needed function prototypes.

#ifndef SDDS_PARKINGLOT_H__ // Safeguard for header file
#define SDDS_PARKINGLOT_H__
#include "ParkingSpot.h" // Includes struct ParkingSpot 
namespace sdds
{
   struct ParkingLot {
      int m_numOfParkingSpots; 
      ParkingSpot* m_parkingSpot; // ParkingSpot pointer to dynamically hold an array parking spots 
   };

   // Prototype for setEmpty()
   void setEmpty(ParkingLot&);

   // Prototype for isEmpty()
   bool isEmpty(const ParkingLot&);

   // Prototype for openParking()
   void openParking(ParkingLot&, int noOfSpots);

   // Prototype for parkCar()
   int parkCar(ParkingLot&);

   // Prototype for returnCar()
   bool returnCar(ParkingLot&, int spotNo);

   // Prototype for closeParking()
   void closeParking(ParkingLot&);
}

#endif // Safeguard for header file