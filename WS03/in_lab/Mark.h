// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 24, 2019

// Mark.h header file containing the necessary constant integer values.
// With the class Mark definition containing the required public member functions prototypes,
// and private data members with a function prototype.

#ifndef _SDDS_MARK_H__ // Safeguard for Mark.h 
#define _SDDS_MARK_H__
#include <ostream> // Include ostream for ostream& display()const function 

namespace sdds
{
   const int DSP_RAW = 1;
   const int DSP_PERCENT = 2;
   const int DSP_ASIS = 3;
   const int DSP_UNDEFINED = -1;

   // Class Mark definition 
   class Mark {
      // Private data memebers and function prototype
      int m_displayMode;
      double m_mark;
      int m_outOf;
      void flushKeyboard()const;
   public:
      // Public function prototypes
      void set(int displayMode);
      void set(double mark, int outOf = 1);
      void setEmpty();
      bool isEmpty()const;
      int percent()const;
      double rawValue()const;
      bool read(const char* prompt);
      std::ostream& display()const;
   };
}

#endif // Safeguard for Mark.h
