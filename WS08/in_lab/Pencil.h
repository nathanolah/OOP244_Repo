// Pencil.h
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 19, 2019

#ifndef SDDS_PENCIL_H__
#define SDDS_PENCIL_H__
#include <iostream>
#include "WriteInstrument.h"
namespace sdds
{
   const int HB_MAX = 2;
   const int GRAPHITE_MAX = 100;

   class Pencil : public WriteInstrument {
      char m_HB_scale[HB_MAX + 1]; // Plus one for null terminator
      int m_graphite;
   public:
      Pencil();
      Pencil(const char* HB_scale, int graphite);
      virtual ~Pencil();
      virtual void write(const char* cString); // 
      virtual void refill(int graphite);
      virtual bool filled()const;
      virtual std::ostream& display(std::ostream& os)const;
      //
      void setEmpty();
      const char* hbScale()const;
      int graphite()const;
   };
}
#endif