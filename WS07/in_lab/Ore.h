// Ore.h
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 3, 2019

#ifndef SDDS_ORE_H_ // Safeguard for header file
#define SDDS_ORE_H_
namespace sdds
{  
   const double DEFAULT_WEIGHT = 300.50;
   const int DEFAULT_PURITY = 20;
   const int CLASS_LEN = 30; // Max string length 

   class Ore {
      double m_weight;
      int m_purity;
      char m_classification[CLASS_LEN + 1]; // Plus one for null terminator
   public:
      Ore();
      Ore(double weight, int purity, const char* classification = "Unknown");
      bool refine();
      std::ostream& display(std::ostream& os)const; 
      std::istream& input(std::istream& is);
      double weight()const;   
      int purity()const;
      const char* classification()const;
      void set(double tempWeight, int tempPurity, const char* tempClassification = "Unknown");
      void setEmpty();
   };
   // Helper operator functions
   std::ostream& operator<<(std::ostream& os, const Ore& ore);
   std::istream& operator>>(std::istream& is, Ore& ore);

}
#endif 
