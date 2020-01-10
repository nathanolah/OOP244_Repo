// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 26, 2019

// Mark.h header file containing the necessary constant integer values.
// With the class Mark definition containing the required public member functions prototypes,
// and private data members with a function prototype.

#ifndef SDDS_MARK_H__ // Safeguard for Mark.h 
#define SDDS_MARK_H__
#include <ostream> // Include ostream for ostream& display()const function 
namespace sdds
{
   const int DSP_RAW = 1;
   const int DSP_PERCENT = 2;
   const int DSP_ASIS = 3;
   const int DSP_UNDEFINED = -1;
   const int DSP_GPA = 4;
   const int DSP_LETTER = 5;

   // Class Mark definition 
   class Mark {
      // Private data memebers and function prototype
      int m_displayMode;
      double m_mark;
      int m_outOf;
      char m_name[51]; // Plus one for null terminator
      void flushKeyboard()const;
      void prnLetter()const;
   public:
      // Public function prototypes
      void set(int displayMode);
      void set(double mark, int outOf = 1);
      void setEmpty();
      bool isEmpty()const;
      int percent()const;
      double rawValue()const;
      bool read(const char* prompt);
      std::ostream& display(int width = 55)const;
      void set(const char* name);
      void set(const char* name, double rawMark, int outOf = 1);
      bool readName(const char* prompt, int maxLen = 50);
      void changeOutOf(int value);
      double GPA()const;
      double letterBasedGPA()const;
   };
}

#endif // Safeguard for Mark.h

