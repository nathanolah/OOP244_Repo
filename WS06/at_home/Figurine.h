// Figurine.h
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 1, 2019

#ifndef _SDDS_FIGURINE_H // Safeguard for header file 
#define _SDDS_FIGURINE_H
namespace sdds
{
   const int MAX_NAME_LEN = 20;
   const double DEFAULT_PRICE = 25.25;

   class Figurine {
      char m_name[MAX_NAME_LEN + 1]; // Plus one for null terminator
      char* m_pose;
      double m_price;
      bool m_copy;
   public:
      Figurine();
      Figurine(const char* name, const char* pose, double price);
      Figurine(const Figurine& RO);
      ~Figurine();
      void setName(const char* name);
      void setPose(const char* pose);
      void setPrice(double price);
      std::ostream& display()const;
      operator bool()const;
      Figurine& operator=(const Figurine& RO);
      bool isCopy()const;
      const char* name()const;
      const char* pose()const;
      double price()const;
      void setEmpty();
   };
   // Helper function prototype 
   bool operator==(const Figurine& LO, const Figurine& RO);
}
#endif