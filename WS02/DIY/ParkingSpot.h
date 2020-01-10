// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 22, 2019

// ParkingSpot.h header file, containing the definition of struct ParkingSpot,
// and the needed function prototypes.

#ifndef SDDS_PARKINGSPOT_H__ // Safeguard for header file
#define SDDS_PARKINGSPOT_H__
namespace sdds
{
   struct ParkingSpot { 
      char m_licensePlate[9]; // plus one for null terminator 
      char* m_makeModel; // Char pointer to dynamically hold string for make and model
   };

   // Prototype for setEmpty()
   void setEmpty(ParkingSpot&);

   // Prototype for isEmpty()
   bool isEmpty(const ParkingSpot&);

   // Prototype for freeSpot()
   void freeSpot(ParkingSpot&);

   // Protoype for print()
   void print(const ParkingSpot&);

   // Prototype for parkCar()
   void parkCar(ParkingSpot&);
}
#endif // Safeguard for header file 
