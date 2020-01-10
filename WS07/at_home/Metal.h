// Metal.h
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 6, 2019

#ifndef SDDS_METAL_H__ // Safeguard for header file 
#define SDDS_METAL_H__
#include "Ore.h" // Include base class Ore
namespace sdds
{  
   const double DEFAULT_MOHS = 2.5;
   const int NAME_LEN = 10;

   // Derived class definition 
   class Metal : public Ore {
      char* m_name;
      double m_mohs;
   public:
      Metal();
      Metal(double weight, int purity, const char* classification,
         const char* name, double mohs);
      ~Metal();
      void setEmpty();
      void refine();
      const char* name()const;
      double mohs()const;
      std::ostream& display(std::ostream& os)const;
      std::istream& input(std::istream& is);
   };

   // Helper functions 
   std::ostream& operator<<(std::ostream& os, const Metal& met);
   std::istream& operator>>(std::istream& is, Metal& met);

}
#endif // !SDDS_METAL_H__
