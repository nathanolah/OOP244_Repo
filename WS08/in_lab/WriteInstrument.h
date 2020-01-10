// WriteInstrument.h
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 19, 2019

#ifndef SDDS_WRITEINSTRUMENT_H__
#define SDDS_WRITEINSTRUMENT_H__
#include <iostream>
namespace sdds
{
   // Abstract base class
   class WriteInstrument {
   public:
      virtual ~WriteInstrument() {}
      virtual void write(const char* cString) = 0;
      virtual void refill(int value) = 0;
      virtual bool filled()const = 0;
      virtual std::ostream& display(std::ostream& os)const = 0;
   };
}
#endif