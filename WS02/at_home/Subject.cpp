// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 17, 2019

// Subject.cpp implementation file containing function definitions for read() of input and output 
// as well as allocation and dellocation of memory for each member of the object. 

#define _CRT_SECURE_NO_WARNINGS // For strcpy()

#include <iostream> // For standard input and output stream
#include <cstring> // For string functions 
using namespace std;
#include "Subject.h" // Includes Subject's data members and function prototypes
#include "utils.h" // Includes utils module's function prototypes

namespace sdds
{
   // Used to input subject name, calls read() from utils module to read up to 70 characters,
   // and prints the error string if there is an error in the input
   void read(char* name) {
      cout << "Enter subject name: ";
      read(name, 70, "Name is too long, only 70 characters allowed!\nRedo Entry: ");
   }
   
   // Used to input number of sections, calls read() from utils module to check if sections are in range
   // from 1 to 10. If number is invalid then error string is printed 
   void read(int& numOfSecs) {
      cout << "Enter number of sections: ";
      read(numOfSecs, 1, 10, "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: "); 
   }

   // Used to input number of students into each section, prints error string if number is invalid
   // Used a for loop to iterate through each section and calls read() to input value into each index
   void read(int students[], int numOfSecs) {
      int i;

      cout << "Enter the number of students in each one of the " << numOfSecs << " sections: " << endl;
      for (i = 0; i < numOfSecs; i++) {
         cout << (i + 1) << ": "; // Print section number 
         read(students[i], 5, 35, "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ");
      }
   }

   // Allocate memory for each member of object Sub
   void read(Subject& Sub) {
      char name[71];
      
      read(name);
      Sub.m_subjectName = new char[71]; 
      strcpy(Sub.m_subjectName, name); // Copy name into member m_subjectName 

      Sub.m_noOfSections = new int;
      read(*Sub.m_noOfSections);

      Sub.m_noOfStdsInSecs = new int[*Sub.m_noOfSections];
      read(Sub.m_noOfStdsInSecs, *Sub.m_noOfSections);
   }

   // Prints the students in each section, and totals up the enrollment 
   // Ternary operator used for if comma insertion is needed
   int report(const Subject& Sub) {
      int i;
      int total = 0;

      for (i = 0; i < *Sub.m_noOfSections; i++) {
         cout << Sub.m_noOfStdsInSecs[i] << (((i + 1) < *Sub.m_noOfSections) ? ',' : '\n');
         total += Sub.m_noOfStdsInSecs[i];
      }
      cout << Sub.m_subjectName << ": " << total << endl;

      return total;
   }

   // Deallocate memory from the members of object Sub
   void freeMem(Subject& Sub) {
      delete[] Sub.m_subjectName;
      Sub.m_subjectName = nullptr; // Nullify to ensure m_subjectName holds a null address

      delete Sub.m_noOfSections;
      Sub.m_noOfSections = nullptr;

      delete[] Sub.m_noOfStdsInSecs;
      Sub.m_noOfStdsInSecs = nullptr;
   }
}
