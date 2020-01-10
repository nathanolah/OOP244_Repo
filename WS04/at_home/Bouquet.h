// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 3, 2019


#ifndef SDDS_BOUQUET_H__ // Safeguard for header file 
#define SDDS_BOUQUET_H__
#include <ostream> // Include ostream 
#include "Flower.h" // Include Flower class 
namespace sdds
{
   const int MESS_MAX_LEN = 25;
   const int MAX_FLOWERS = 3;

   class Bouquet {
      double b_price;
      char* b_message; // char pointer for allocation of memory
      Flower* b_flowers; // Flower pointer for allocation of memory
      int b_flowerCount;
   public:
      // Constructors/Destructor
      Bouquet();
      Bouquet(const Flower* flower, int numOfFlowers = MAX_FLOWERS, const char* message = nullptr);
      ~Bouquet();
      // Function prototypes
      const char* message()const;
      double price()const;
      bool isEmpty()const;
      void setEmpty();
      void setMessage(const char* prompt);
      void discardBouquet();
      void arrangeBouquet();
      std::ostream& display()const;
   };
}
#endif // !