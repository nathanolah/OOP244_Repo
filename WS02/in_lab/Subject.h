// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 17, 2019

// Subject.h safeguarded header file containing function prototypes,
// and struct type Subject with all required pointer data members.

#ifndef SDDS_SUBJECT_H__ // Safeguard for header file 
#define SDDS_SUBJECT_H__
namespace sdds
{  
   // struct Subject containing pointer data members
   struct Subject {
      int* m_noOfSections;
      int* m_noOfStdsInSecs;
      char* m_subjectName;
   };

   // Prototype for read() used for inputting subject name
   void read(char* name);

   // Prototype for read() used for inputting number of sections 
   void read(int& numOfSecs);

   // Prototype for read() used for inputting number of students into sections 
   void read(int students[], int numOfSecs);

   // Prototype for read() to allocated memory 
   void read(Subject& Sub);

   // Prototype for report() used to print the output
   int report(const Subject& Sub);

   // Prototype for freeMem() to deallocated memory
   void freeMem(Subject& Sub);
}
#endif // Safeguard for header file 