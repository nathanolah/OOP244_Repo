// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 30, 2019

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include "PubRecord.h"
namespace sdds
{
   class Book : public PubRecord {
      long long m_ISBNno;
      int m_memberID; 
      Date m_date;
   public:
      Book();
      Book(const Book& ro);
      Book& operator=(const Book& ro);
      virtual ~Book();
      void setEmpty();
      char recID()const;
      int memberID()const;
      void checkIn();
      void checkOut();
      void readMemberID();
      std::istream& read(std::istream& is = std::cin);
      void readBookName();
      void readISBNno();
      std::ostream& write(std::ostream& os = std::cout)const;
   };
}
#endif

