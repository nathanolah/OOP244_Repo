// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// September 28, 2019

// MarksReport.cpp implementation file containing the function 
// definitions for initialize(), getMarks(), print(), and terminate().

#include <iostream> // Include input and output stream
using namespace std;
#include "MarksReport.h" // Includes class MarksReport
#include "Mark.h" // Includes class Mark's data members with member functions and constant int values
#include "ReportsUtils.h" // Includes read() and line() functions 
namespace sdds
{
   // Initializes member variables, ready for data entry 
   // Sets variables to an empty state
   void MarksReport::initialize() {
      m_marks = nullptr;
      m_numMarks = 0;
      m_title[0] = '\0';
   }

   // Gets the report name and number of marks from the user
   // Allocates memory for an array of objects, based off of the number of marks
   void MarksReport::getMarks() {
      int i;

      // Gets report name
      cout << "Enter the report Name: ";
      read(m_title, 70, "Title is too long must be 70 characters or less"); 

      // Gets number of marks
      cout << "Enter the number of marks: ";
      read(m_numMarks, "Invalid number try again"); 

      // Allocates memory for the array of object m_marks
      m_marks = new Mark[m_numMarks];

      
      cout << "Please enter " << m_numMarks << ((m_numMarks == 1) ? " mark:" : " marks:") << endl;

      // Gets mark info from user
      for (i = 0; i < m_numMarks; i++) {
         m_marks[i].setEmpty(); // Initialize variables to empty state
         m_marks[i].set(DSP_LETTER); 
         cout << (i + 1) << ": ";

         // While user input is invalid
         while (!m_marks[i].readName("Subject Name: ", 6) || !m_marks[i].read("Mark (mark/outof): ")) {
            cout << "Invalid Entry, retry!" << endl;
            m_marks[i].set(DSP_LETTER); 
         }
      }

      cout << "Entry Completed!" << endl << endl;
      
      // Prints 70 of '-' characters
      line(70, '-') << endl; 
   }

   // Prints the marks entered with letter grade for each course
   // Prints GPA with lowest and highest mark
   void MarksReport::print() {
      int i;
      int highest = -1;
      int lowest = 101;
      double gpa = 0;

      Mark result;
      result.setEmpty();

      // Displays report name 
      cout << m_title << endl;
      line(70, '-') << endl;
      cout << "Marks entered:" << endl;
      
      // Gets GPA, lowest and highest mark
      for (i = 0; i < m_numMarks; i++) {
         m_marks[i].display(66) << endl; 
         gpa += m_marks[i].letterBasedGPA();

         if (m_marks[i].percent() > highest) {
            highest = m_marks[i].percent();
         }

         if (m_marks[i].percent() < lowest) {
            lowest = m_marks[i].percent();
         }
      }
      line(70, '-') << endl; 

      // Displays lowest mark
      result.set(lowest, 100); 
      result.set(DSP_PERCENT);
      result.set("Lowest Mark");
      line(30, ' '); 
      result.display(36) << endl; 

      // Displays highest mark
      result.set(highest, 100); 
      result.set(DSP_PERCENT);
      result.set("Highest mark");
      line(30, ' ');
      result.display(36) << endl; 

      // Displays GPA
      result.set(gpa / m_numMarks, 4);
      result.set(DSP_GPA);
      result.set("GPA");
      line(30, ' ');
      result.display(36) << endl; 
   }

   // Deallocates and nullifys memory for m_marks
   // Resets data members to an empty state 
   void MarksReport::terminate() {
      delete[] m_marks;
      m_marks = nullptr;
      m_numMarks = 0;
      m_title[0] = '\0';
   }
}