// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 19, 2019

#ifndef SDDS_READWRITEABLE_H__
#define SDDS_READWRITEABLE_H__
namespace sdds
{
   class ReadWriteable { //Abstract base class
   public :
      // Virtual destructor
      virtual ~ReadWriteable() {}
      // Pure virtual functions
      virtual std::ostream& write(std::ostream& os = std::cout)const = 0;
      virtual std::istream& read(std::istream& is = std::cin) = 0;
    
   };

   // Helper Operator functions
   std::ostream& operator<<(std::ostream& os, const ReadWriteable& toBePrinted);
   std::istream& operator>>(std::istream& is, ReadWriteable& tobeRead);
}
#endif