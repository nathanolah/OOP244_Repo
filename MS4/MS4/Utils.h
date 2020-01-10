// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 18, 2019

#ifndef SDDS_UTILS_H__ // Safeguard for Utils.h
#define SDDS_UTILS_H__
namespace sdds
{
   // Prototype for readValue() function 
   void readValue(int& val, int min, int max, const char* ErrorMess = "");
   void readValue(unsigned int& val, unsigned int min, unsigned int max, const char* ErrorMess = "");
   void readValue(long long& val, long long min, long long max, const char* ErrorMess = "");
   
   // Prototype for readString() function
   void readString(char* str, int len, const char* errorMessage = "");
}
#endif
