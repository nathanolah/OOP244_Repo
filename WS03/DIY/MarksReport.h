// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 28, 2019


#ifndef SDDS_MARKSREPORT_H__ // Safeguard for MarkReport.h
#define SDDS_MARKSREPORT_H__
#include "Mark.h" // Includes class Mark
namespace sdds
{  
   // Used for character input size 
   const int maxLen = 71;

   // MarkReport class definition 
   class MarksReport {
      char m_title[maxLen];
      Mark* m_marks;
      int m_numMarks;
   public: 
      // Public function prototypes for MarksReport.cpp
      void initialize();
      void getMarks();
      void print();
      void terminate();
   };
}
#endif // Safeguard for MarkReport.h

