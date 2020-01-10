// Pen.h
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 19, 2019

#ifndef SDDS_PEN_H__
#define SDDS_PEN_H__
#include <iostream>
#include "WriteInstrument.h"
namespace sdds
{  
   const int INK_MAX = 50;

   class Pen : public WriteInstrument {
      char* m_style;
      int m_ink;
   public :
      Pen();
      Pen(const char* style, int ink);
      virtual ~Pen();
      //
      virtual void write(const char* cString);
      virtual void refill(int ink);
      virtual bool filled()const;
      virtual std::ostream& display(std::ostream& os)const;
      void setEmpty();
      const char* style()const;
      int ink()const;
   };
}
#endif