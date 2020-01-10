// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 18, 2019

// School.cpp implementation file containing function definitions for read(),
// report(), and freeMem(). As well as allocation and deallocation of the array Sch.m_subjects.

#define _CRT_SECURE_NO_WARNINGS // To disable deprecation

#include <iostream> // For standard input and output stream
#include <cstring> // For strcpy() and strlen() 
using namespace std;
#include "School.h" // Includes Schools's data members and function protoypes 
#include "Subject.h" // Includes Subject's data members and function prototypes 
#include "utils.h" // Includes utils module's functions prototypes
namespace sdds
{

   // Used to input school's name, calls read() from the utils module to read up to set amount of characters,
   // and prints the error string if there is an error in the input.
   void read(School& Sch) {
      char schoolName[61];
      int i;

      cout << "Please enter the name of the school:\n> ";
      read(schoolName, 60, "Name is too long, only 60 characters allowed!\nRedo Entry: ");

      // Allocate dynamic memory for Sch.m_name
      Sch.m_name = new char[strlen(schoolName) + 1]; // string length of schoolName plus 1 for null terminator 
      strcpy(Sch.m_name, schoolName); // Copy into Sch's member m_name
      
      // Read in number of subjects, checks for in range number 
      cout << "Please enter the number of subjects offered by " << Sch.m_name << ": ";
      read(Sch.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ");

      // Allocate dynamic memory for the array of Sch.m_subjects, to the size of Sch.m_noOfSubjects
      Sch.m_subjects = new Subject[Sch.m_noOfSubjects];

      for (i = 0; i < Sch.m_noOfSubjects; i++) {
         cout << (i + 1) << ") ------------------------------" << endl; 
         read(Sch.m_subjects[i]); // Input values for each subject
      }
   }

   // Prints the output of each element of the instance Sch.m_subjects[] 
   // report() returns number of students in sections for the total enrollment value
   int report(const School& Sch) { 
      int i;
      int total = 0;

      cout << Sch.m_name << endl << "Subject Enrollments" << endl; 

      for (i = 0; i < Sch.m_noOfSubjects; i++) { 
         total += report(Sch.m_subjects[i]);
      }

      cout << "Total enrollment: " << total << endl;

      return total;
   }

   // Deallocates dynamic memory, calls freeMem() deallocates and nullifies each member 
   void freeMem(School& Sch) {
      for (int i = 0; i < Sch.m_noOfSubjects; i++) { 
         freeMem(Sch.m_subjects[i]); // Dellocate each member 
      }

      // Deallocate dynamic memory 
      delete[] Sch.m_subjects;
      Sch.m_subjects = nullptr; // Nullify Sch.m_subjects 

      delete[] Sch.m_name;
      Sch.m_name = nullptr; 
   }
}