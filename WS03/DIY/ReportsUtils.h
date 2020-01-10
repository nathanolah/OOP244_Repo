// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 28, 2019


#ifndef SDDS_REPORTSUTILS_H__ // Safeguard for ReportsUtils.h
#define SDDS_REPORTSUTILS_H__
#include <ostream> // Includes output stream

namespace sdds 
{
   // read() function prototype
   void read(char* str, int len, const char* errorMessage);

   // read() function prototype
   void read(int& num, const char* errorMessage);

   // line() function prototype
   std::ostream& line(int len, char ch);
}
#endif // Safeguard for ReportsUtils.h