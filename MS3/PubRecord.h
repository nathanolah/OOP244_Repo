// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 20, 2019

#ifndef SDDS_PUBRECORD_H__ // Safeguard for header file
#define SDDS_PUBRECORD_H__
#include "ReadWriteable.h"
#include "Date.h"
namespace sdds
{  
   const int SDDS_CONSOLE = 0;
   const int SDDS_FILE = 1;
  
   class PubRecord : public ReadWriteable { // Derived class
      char* m_name;
      int m_shelfNumber;
      int m_typeOfMedia;
   protected:
      void name(const char* name);
      const char* name()const;
      void allocateAndCopy(const char* cString);
   public:
      virtual char recID()const = 0;
      virtual ~PubRecord();
      PubRecord();
      PubRecord(const PubRecord& RO);
      // Member Operators 
      PubRecord& operator=(const PubRecord& RO);
      bool operator==(const char letter)const;
      bool operator==(const char* str)const;
      operator bool()const;
      // Member functions
      bool isEmpty()const;
      void setEmpty();
      void mediaType(int type);
      int mediaType()const;
      int shelfNo()const;
      void readShelfNo(); 
      //void allocateAndCopy(const char* cString);

   };
}
#endif // !SDDS_PUBRECORD_H__

