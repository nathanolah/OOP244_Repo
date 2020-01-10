// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 19, 2019

#include <iostream>
#include "ReadWriteable.h"
namespace sdds
{
   // Helper insertion operator
   std::ostream& operator<<(std::ostream& os, const ReadWriteable& RO) {
      return RO.write(os);
   }

   // Helper extraction operator 
   std::istream& operator>>(std::istream& is, ReadWriteable& RO) {
      return RO.read(is);
   }

}