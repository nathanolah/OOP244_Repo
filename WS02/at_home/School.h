// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 18, 2019

// School.h safeguarded header file containing function prototypes,
// and struct type School with all required data members 

#ifndef SDDS_SCHOOL_H__ // Safeguard header file 
#define SDDS_SCHOOL_H__
#include "Subject.h" // Include struct Subject 
namespace sdds
{
   struct School {
      int m_noOfSubjects; // To hold number of subjects 
      Subject* m_subjects; // Pointer for dynamically allocated array of subjects
      char* m_name; // Char pointer to hold the name of School dynamically 
   };

   // Prototype for read() used for inputting school name
   void read(School& Sch);

   // Prototype for report() used to print the output 
   int report(const School& Sch);

   // Prototype for freeMem() to deallocate memory
   void freeMem(School& Sch);
}

#endif // Safeguard header file