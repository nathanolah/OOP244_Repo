// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 30, 2019

#ifndef SDDS_MAGAZINE_H__ // Safeguard for header file
#define SDDS_MAGAZINE_H__
#include "PubRecord.h"
namespace sdds
{
   class Magazine : public PubRecord {
      int m_volume; 
      int m_issueNo;
   public:
      Magazine();
      Magazine(const Magazine& RO);
      Magazine& operator=(const Magazine& RO);
      virtual ~Magazine();
      // Member functions
      char recID()const; 
      void checkIn();
      void checkOut();
      std::istream& read(std::istream& is = std::cin);
      std::ostream& write(std::ostream& os = std::cout)const;
      void readName();
      void readVolume();
      void setVolume(int value);
      void readIssueNo();
      void setIssueNo(int issue);
      int volume()const;
      int issue()const;
   };
}
#endif // !SDDS_MAGAZINE_H__

