// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 1, 2019

// Flower.h header file, containing the definition of class Flower.
// The class Flower contains the needed public function prototypes as well as the 
// constructor and destructor for the Flower module.

#ifndef SDDS_FLOWER_H__ // Safeguard for header file
#define SDDS_FLOWER_H__
namespace sdds
{
   const int NAME_MAX_LEN = 25; // Name max length
   const int COL_MAX_LEN = 15; // Colour max length 

   class Flower {
      // Private data memebers
      char* f_name;
      char* f_colour;
      double f_price;
   public:
      // Constructors/Destructor
      Flower();
      Flower(const char* name, const char* colour, double price);
      ~Flower();
      // Function prototypes
      const char* name()const;
      const char* colour()const;
      double price()const;
      bool isEmpty()const;
      void setEmpty();
      void setName(const char* prompt);
      void setColour(const char* prompt);
      void setPrice(const char* prompt);
      void setFlower();
      std::ostream& display()const;
      void setName(const char* name, int len);
      void setColour(const char* colour, int len);
      void setPrice(double price);
   };
}
#endif //!